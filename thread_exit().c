#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void*thread_1(void*p)
{
        while(1)
        {
                printf("In the thread_1\n");
                pthread_exit(0);
                printf("thread_1 therminated");
        }
}
void*thread_2(void*p)
{
        while(1);
        {
                pthread_exit(0);
                printf("In the thread_2\n");
                printf("thread_2 terminated\n");
                printf("bye....\n");
        }
}
int main()
{
        pthread_t t1,t2;
        printf("Under the process\n");
        pthread_create(&t1,0,thread_1,0);
        pthread_create(&t2,0,thread_2,0);
        while(1);
}
