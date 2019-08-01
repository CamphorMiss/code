#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
void handler(int signo)
{
  pid_t id;
  while(id=(waitpid(-1,NULL,WNOHANG)>0))
  {
    printf("wait success...\n");
  }
  printf("wait exit!\n");
}
int main()
{
  signal(SIGCHLD,handler);
  pid_t id=fork();
  if(id==0)
  {
  //我是孩子
  sleep(3);
  exit(1);
  }
  else
  {
   //我是爸爸
   while(1)
   {
    printf("father  is  runing ...\n");
    sleep(1);
   }
  }
  return 0;
}
