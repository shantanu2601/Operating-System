#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <limits.h>

typedef struct matrix
{
    int flag1;int flag2;

}matrix;

matrix* mat;

int*matrix1;int *matrix2;int *flag;

int main(int argc,char *argv[])
{
    mat = (struct matrix*) malloc(sizeof(struct matrix));
    key_t mt1=ftok("OldSc.c",65);
    int matrix1_id=shmget(mt1,sizeof(int)*1000000,0666|IPC_CREAT);
    matrix1 = (int *)shmat(matrix1_id,NULL,0);
    key_t mt2=ftok("OldSc.c",66);
    int matrix2_id=shmget(mt2,sizeof(int)*1000000,0666|IPC_CREAT);
    matrix2 = (int *)shmat(matrix2_id,NULL,0);
    key_t fl1=ftok("OldSc.c",67);
    int flag_id=shmget(fl1,sizeof(int)*1000000,0666|IPC_CREAT);
    flag = (int *)shmat(flag_id,NULL,0);
    key_t flagstruct=ftok("OldSc.c",68);
    int flagstruct_id=shmget(flagstruct,sizeof(int)*1000000,0666|IPC_CREAT);
    mat = (struct matrix *)shmat(flagstruct_id,NULL,0);
    // int mt2=shmget(IPC_PRIVATE,sizeof(int)*1000000,0666|IPC_CREAT);
    // matrix2 = (int *)shmat(mt2,NULL,0);
    // int fl1=shmget(IPC_PRIVATE,sizeof(int)*1000000,0666|IPC_CREAT);
    // flag = (int *)shmat(fl1,NULL,0);
    for(int i=0;i<1000000;i++){
        flag[i]=0;
    }
    char strid1[100+1] = {'\0'};
    sprintf( strid1, "%d", mt1 );
    // char strid2[100+1] = {'\0'};
    // sprintf( strid2, "%d", mt2 );
    // char strid3[100+1] = {'\0'};
    // sprintf( strid3, "%d", fl1 );
    const char *argvar[]={"./reader.out",argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],strid1,(char *)NULL};
    // for(int i=1;i<=9;i++){
    //     printf("%s\n",argvar[i]);
    // }
    mat->flag1=0;mat->flag2=0;
    double  time_quantum;
    printf("Enter time quantum to be used:");
    scanf("%lf",&time_quantum);
    printf("\n");
    int pid[2];
    //time_t st77=time(NULL);    
    //double bt1=0.0;double w1=0.0;
    //double bt2=0.0;double w2=0.0;
    pid[0]=fork();
    if(!pid[0])
    {        
         execvp("./writer.out",argvar);
    }
    else
    {
        pid[1]=fork();
        if(pid[1]==0)
        {
            
             sleep(2);
             printf("Child created\n");
    	       execvp("./reader.out",argvar);
        }
        else
        {
           //kill(pid[0], SIGSTOP);kill(pid[1], SIGSTOP);
               while(!(mat->flag1==1 && mat->flag2==1))
               {
                    if(mat->flag1==0)
                    { 
                    
                        //time_t c1=time(NULL);
                        kill(pid[1], SIGSTOP);
                        kill(pid[0], SIGCONT);
                        usleep(time_quantum);
                        kill(pid[0], SIGSTOP);
                        //time_t c2=time(NULL);
                        //double d=(double)((difftime(c2,c1)));
                        //bt1+=time_quantum;
                        //if(mat->flag2==0)
                        //w2+=time_quantum;
                    }
                
                
		            if(mat->flag2!=1)
                    { 
                        //time_t c1=time(NULL);
                        kill(pid[0], SIGSTOP);
                        kill(pid[1], SIGCONT);
                        usleep(time_quantum);
                        kill(pid[1], SIGSTOP);
                        //time_t c2=time(NULL);
                        //double d=(double)((difftime(c2,c1)));
                        //bt2+=time_quantum;
                        
                        //if(mat->flag1==0)
                        //w1+=time_quantum;
                    }
                }

           }
    
        }  
    wait(NULL);wait(NULL);
  
    return 0;
    
}