#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *func(void *str)
{
    int i=3;
    while(i--)
    {
        printf("i am thread,my name is %s\n",str);
        sleep(1);
        
    }
    pthread_exit((void *)3);
}
int main()
{
    //创建一个线程
    pthread_t tid;
    pthread_create(&tid,NULL,&func,"newthread");
    while(1)
    {
    //主线程
    printf("i am main thread....\n");
    sleep(2);
    break;
    }
    void * ret;
    pthread_join(tid,&ret);
    printf("exit code is %d\n",(int)ret);
    return 0;


}
