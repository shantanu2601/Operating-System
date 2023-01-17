#include<stdio.h>
#include <stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
typedef struct matrix
{
    int flag1;int flag2;

}matrix;

matrix* mat;
int A[1000][1000];
int B[1000][1000];
int rows_a;int columns_a;int rows_b;int columns_b;
int *matrix1;
int *matrix2;
int *flag;
int columns;int rows;
FILE*myFile1;
FILE*myFile2;
struct parm
{
  int start; // starting row
  int finish; // finishing row
  int tc;
};

int read_matrix(FILE* ptr, int matr[1000][1000]){
    char myF[7777];char delim[] = " ";
    int r=0;
    while(fgets(myF,sizeof(myF),ptr))
    {

        //(mat->c)++;
        char *ptr = strtok(myF, delim);
        int c=0;
        while(ptr != NULL)
	      {
		      int v=atoi(ptr);
          printf("%d ",v);
          matr[r][c++]=v;
          //matr[mat->c][c++]=v;
		      ptr = strtok(NULL, delim);
        
	      }
        r++;
        printf("\n");
    }
    fclose(ptr); 
    return 1;

 


}

void funct(void*range){
    struct parm *prange = range;
    int start = prange->start;
    int finish = prange->finish;
    int tc = prange->tc;
    printf("MASTER:start=%d finish=%d tc=%d threadid:%d\n",start,finish,tc,pthread_self());  
    for(int i=start;i<=finish;i++){
        for(int j=0;j<columns_a;j++){
            matrix1[i*columns_a+j]=A[i][j];
            //printf("MASTER:matrix1=%d ",matrix1[i*columns_a+j]);
            //printf("MASTER:A=%d ",A[i][j]);
            //printf("MASTER:A=%d ",i*columns+j);
        }
        printf("\n");
    }
    //sleep(1);
    flag[tc]=1;
    pthread_exit(0);
    //return 0;
}
int main(int argc,char *argvar[]){
    //row_a=50;col_a=20;row_b=20;col_b=50;
    rows_a=atoi(argvar[1]);columns_a=atoi(argvar[2]);rows_b=atoi(argvar[2]);columns_b=atoi(argvar[3]);
    printf("P1:rows_a= %d columns_a= %d rows_b= %d columns_b= %d\n",rows_a,columns_a,rows_b,columns_b);
    myFile2=fopen(argvar[4],"r"); 
    myFile1=fopen(argvar[5],"r");
    printf("Here\n");


    //while(1){
      int val1=read_matrix(myFile2,A);
      int val2=read_matrix(myFile1,B);
      printf("Here2\n");
      // if(val1==1 && val2==1){
      //   break;
      // }
    //}
    for(int i=0;i<rows_a;i++){
      for(int j=0;j<columns_a;j++){
        printf("%d ",A[i][j]);
      }
      printf("\n");
    }
    key_t mt1=ftok("scheduler.c",65);
    int matrix1_id=shmget(mt1,sizeof(int)*1000000,0666|IPC_CREAT);
    matrix1 = (int *)shmat(matrix1_id,NULL,0);
    key_t mt2=ftok("scheduler.c",66);
    int matrix2_id=shmget(mt2,sizeof(int)*1000000,0666|IPC_CREAT);
    matrix2 = (int *)shmat(matrix2_id,NULL,0);
    key_t fl1=ftok("scheduler.c",67);
    int flag_id=shmget(fl1,sizeof(int)*1000000,0666|IPC_CREAT);
    flag = (int *)shmat(flag_id,NULL,0);
    key_t flagstruct=ftok("scheduler.c",68);
    int flagstruct_id=shmget(flagstruct,sizeof(int)*1000000,0666|IPC_CREAT);
    mat = (struct matrix *)shmat(flagstruct_id,NULL,0);
    // int mt1=atoi(argvar[7]);
    // matrix1 = (int *)shmat(mt1,NULL,0);
    // int mt2=atoi(argvar[8]);
    // matrix2 = (int *)shmat(mt2,NULL,0);
    // int fl1=atoi(argvar[9]);
    // flag = (int *)shmat(fl1,NULL,0);
    
    //while(1){
     for(int i=0;i<rows_b;i++){
        for(int j=0;j<columns_b;j++){
            matrix2[i*columns_b+j]=B[i][j];
            printf("MASTER:matrix1=%d ",matrix2[i*columns_b+j]);
            //printf("MASTER:A=%d ",A[i][j]);
            //printf("MASTER:A=%d ",i*columns+j);
        }
        printf("\n");
      }
      //break;
    //}
    int dhaage = 1;
    printf("MASTER:Threads to use?\n");
    scanf("%d", &dhaage);
    

    // int pid=fork();
    // if(pid==0){
  	//     printf("Child created\n");
    // 	execvp("./reader.out",argv);
    // }

  
    pthread_t thr_id [dhaage];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
  
  
    int k;
    int N = rows_a;
    int dh = dhaage;
  
    int rows = N/dh; // number of rows per thread

      // create dhaage and have them calculate their rows
    int i = 0, j, row;
    for(i = 0; i < dh-1; i++)
	{    
    //gets row index
	  row = i * rows;
      
	  struct parm *data = (struct parm*) malloc(sizeof(struct parm));
    //gets start row index
	  data->start = row;
    //gets finish row index
	  data->finish = row + rows - 1;
      data->tc=i;
	  // create thread for that set of rows
        printf("MASTER:Thread %d created\n", i);
	    pthread_create(&thr_id[i], &attr, funct, data);

	}
      
      
      row = i * rows;
      struct parm *data = (struct parm*) malloc(sizeof(struct parm));
      data->start = row;
      data->finish = N-1;
      data->tc=i;
      printf("Thread %d created\n", i);
      pthread_create(&thr_id[dh -1], &attr, funct, data);
      
      i = 0;
      while(i < dh){
        pthread_join(thr_id[i], NULL);
        i++;
      }

  //sleep(10);
  mat->flag1=1;
  printf("MASTER FINISHED\n");
  //wait(NULL);
  exit(0);
  return 0;

}
