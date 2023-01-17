#include<stdio.h>
#include <stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include <pthread.h>
#include <time.h>
// #define M 4
// #define N 3
// #define P 3
typedef struct matrix
{
    int flag1;int flag2;

}matrix;
matrix* mat;

struct parm
{
  int start; // starting row
  int finish; // finishing row
  int tc;
};
int *matrix1;
int *matrix2;
int*matrix3;
int *flag;
int A[1000][1000];
//int B[1000][1000]={{2,3,4},{5,6,7},{8,9,10}};
int B[1000][1000];
int C[1000][1000];
FILE*myFile1;
FILE*myFile2;

int rows_a, columns_a;
int rows_b, columns_b;
int rows_c, columns_c;
void *math(void* range)
{
  struct parm *prange = range;
  int start = prange->start;
  int finish = prange->finish;
  int tc=prange->tc;
  printf("CHILD:start=%d finish=%d tc=%d threadid:%d\n",start,finish,tc,pthread_self());
  printf("Going to read matrix \n");
   for(int i=start;i<=finish;i++){
        for(int j=0;j<columns_a;j++){
           A[i][j]= matrix1[i*columns_a+j];
           //printf("CHILD: A=%d\n",A[i][j]);
        }
    }
  // perform multiplication on portion of matrix
  int i = start, j = 0, k = 0;
  while(i <= finish){
    j = 0;
    while(j < columns_b){
      k = 0;
      while(k < columns_a){
        C[i][j] += A[i][k] * B[k][j];
        k++;
      }
      j++;
    }

    i++;
  }
  // end thread
  flag[tc]=3;
  
  //return 0;
  pthread_exit(0);
}
int main(int argc,char*argv[]){
    //sleep(10);
    FILE* fp;
    fp = fopen("out.txt","w");
    rows_a =atoi(argv[1]);
    columns_a = atoi(argv[2]);
    rows_b = atoi(argv[2]);
    columns_b = atoi(argv[3]);
   // printf("P2:rows_a= %d columns_a= %d rows_b= %d columns_b= %d\n",rows_a,columns_a,rows_b,columns_b);
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

    // matrix1=(int *)shmat(atoi(argv[7]),NULL,0);
    // matrix2=(int *)shmat(atoi(argv[8]),NULL,0);
    // flag=(int *)shmat(atoi(argv[9]),NULL,0);
    // int mt3=shmget(IPC_PRIVATE,sizeof(int)*1000000,S_IRUSR|S_IWUSR);
    // matrix3=(int *)shmat(mt3,NULL,0);
  
    //while(1){
      for(int i=0;i<rows_b;i++){
        for(int j=0;j<columns_b;j++){
          B[i][j]=matrix2[columns_b*i+j];
        }
      }
      //break;
    //}
    printf("here3\n");
    
    int dhaage = 2;
    printf("CHILD:Count of Threads?\n");
     scanf("%d", &dhaage);


    /* initialize dhaage */
    pthread_t tid [dhaage];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
  
  
    
  
    int dh = dhaage;int N=rows_a;
    /*perform multiplication with specified number of dhaage*/
    int rows = N/dh; // number of rows per thread
    //int rows_remainder = N%thr;

    // create dhaage and have them calculate their rows
    int cnt = 0, j, row;
    //int test=100; 
      
    while(1){
        int isRun=1;
        for(int i=0;i<dh;i++){
            if(flag[i]!=3){
                isRun=0;
                break;
             }
        }
        if(isRun==1){
            //printf("CHILD:Finished\n");
            break;
        }
        for(int i=0;i<dh;i++){
            if(i==dh-1 && flag[i]==1 && N%dh!=0){
                struct parm *data = (struct parm*) malloc(sizeof(struct parm));
                //gets row index
                row = i*rows;
                //starting row for thread i
                data->start = row;
                //ending row for thread i
                data->finish = N - 1;
                data->tc = i;
                printf("CHILD:Thread %d created\n", i);
                flag[i]=2;
                pthread_create(&tid[i], &attr, math, data);
            }
            else if(flag[i]==1){
              //printf("P2:%d %d\n",i,flag[i])
                row= i*rows;
                struct parm *data = (struct parm*) malloc(sizeof(struct parm));
                data->start = row;
                data->finish = row + rows - 1;
                data->tc=i;
                printf("CHILD:Thread %d created\n", i);
                flag[i]=2;
                pthread_create(&tid[i], &attr, math, data);
            }
    }
    }  
    // increment thread count and join all dhaage and output
    for(int cnt = 0; cnt< dh; cnt++)
	{
	  pthread_join(tid[cnt], NULL);
	}
	//sleep(10);
  printf("%d\n",C[0][0]);
     while(1){
     	int isRun=1;
        for(int i=0;i<dh;i++){
            if(flag[i]!=3){
                isRun=0;
                break;
             }
        }
        if(isRun==0){
            printf("CHILD:waiting\n");
            continue;
        }
        	
     	printf("CHILD:OUTPUT OF C\n");    
     	for(int i=0;i<rows_a;i++){
            for(int j=0;j<columns_b;j++)
            {
                //matrix3[i*columns_b+j]=C[i][j];
                printf("%d ",C[i][j]);
                fprintf(fp,"%d ",C[i][j]);
            }
            fprintf(fp,"\n");
     	}
     	break;
     }		
    printf("CHILD FINISHED\n");
    fclose(fp);
    mat->flag2=1;
    exit(0);
    return 0;

}

