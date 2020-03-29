#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
#define MIN_PID 100
#define MAX_PID 1000
#define NO_OF_Process 16
int pid1[MAX_PID-MIN_PID]={0};
void *Routine(void *arg){
    int tid1 =  *(( int* )arg);
    int id1 = allocate_pid();
    if(id1>0)
    {
        printf("Thread [%3d] PID [%3d] Allocated\n",tid1,id1+MIN_PID);

        int r1=1+rand()%30;

        sleep(r1);
        printf("Thread [%3d] PID [%3d] Released after %d sec\n",tid1,id1+MIN_PID,r1);
        release_pid(id1);
    }
    else{
          if(id1==-1){
        puts("No PID available.");
           }
     }
    pthread_exit(NULL);
}
void release_pid(int id1){
    pid1[id1]=0;
}
int allocate_pid(void){
    int i,flag=1;
    for(i=0; i<MAX_PID-MIN_PID; i++){
        if(pid1[i]==0){
            pid1[i]=1;
            flag=0;
            break;
        }
    }
    return flag?-1:i;
}
int main(){
    int i;
    pthread_t process[NO_OF_Process];
    srand(time(NULL));
    for(i=0; i<NO_OF_Process; i++){
        if(pthread_create(&process[i],NULL,Routine,(void*)&i))
            return -1*printf("Error in thread %d creation!!!\n",i);
    }
    for(i=0; i<NO_OF_Process; i++)
        pthread_join(process[i],NULL);
    //wait(NULL);
    return 0*printf("\nSUCCESSFUL EXIT\n");
}
