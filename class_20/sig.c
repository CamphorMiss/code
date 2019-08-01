#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void handler(int signo)
{
   printf("signo is %d\n",signo);
   exit(1);
}
int main()
{
   sigset_t set,oset;
   sigemptyset(&set);
   struct sigaction a;
   a.sa_handler=handler;
   sigaction(2,&a,NULL);
   while(1)
   {
       sleep(1);
   printf("i am runing...\n");
   }
   return 0;
}
