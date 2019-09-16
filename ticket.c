#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int tick=100;
void* Gettick(void *arg)
{
    while(1)
    {
   if(tick>0)
    {
        usleep(10000);
        printf("%s get a tick. no.%d\n",(char *)arg,tick);
        tick--;
    }
   else
       break;
    }
}
int main()
{
pthread_t p1,p2,p3,p4;
pthread_create(&p1,NULL,Gettick,"p1");
pthread_create(&p2,NULL,Gettick,"p2");
pthread_create(&p3,NULL,Gettick,"p3");
pthread_create(&p4,NULL,Gettick,"p4");
pthread_join(p1,NULL);
pthread_join(p2,NULL);
pthread_join(p3,NULL);
pthread_join(p4,NULL);
return 0;
}
