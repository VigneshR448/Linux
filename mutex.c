#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int g=0;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
void*thread_1(void*p)
{
        printf("thread_1 started execution\n");
       printf("waiting for lock\n");
       pthread_mutex_lock(&m);
       printf("mutex is locked by thread_1\n");
       printf("thread_1 g value :%d\n",g);
       printf("thread_1 updating g value to 2\n");
       g++;
       printf("thread_1 g value :%d\n",g);
       sleep(20);
       printf("thread_1 g value :%d\n",g);
       printf("lock released by thread_1\n");
       pthread_mutex_unlock(&m);
       printf("thread_1 terminated..\n");
}
void*thread_2(void*p)
{
        printf("thread_2 started execution\n");
        printf("waiting for lock\n");
        pthread_mutex_lock(&m);
        printf("mutex is locked thread_2\n");
        printf("thread_2 g value :%d\n",g);
        sleep(3);
        printf("thread_2 want to update g value as 100\n");
        sleep(2);
        g=100;
        printf("thread_2 g value :%d\n",g);
        sleep(2);
        printf("lock released by thread_2\n");
        pthread_mutex_unlock(&m);
        printf("thread_2 terminated..\n");
}


int main()
{
        pthread_t t1,t2;
        pthread_create(&t1,0,thread_1,0);
        sleep(1);
        pthread_create(&t2,0,thread_2,0);
        while(1);
}
