#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    pid_t id=fork();
    if(id==0)
    {//child
              printf("i am a child! pid:%d  ppid:%d\n",getpid(),getppid());
              sleep(1);
              exit(21);
    }
    else if(id<0)
    {
      printf("fork errno!\n");
      return -1;
    }
    else
    {
        int status=0;
         pid_t ret= waitpid(id,&status,WNOHANG);
         while(ret==0)
         {
            pid_t ret= waitpid(id,&status,WNOHANG);

         }
         if(WIFEXITED(status)&&ret==id)
         {//shuo ming chengxu zhengchang tuichu
             printf("wait child success,child code is %d",WEXITSTATUS(status));
         }else
         {
         printf("wait false!\n ");
         return -1;
         }
    }

    return 0;
}
