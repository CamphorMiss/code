#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        pid_t id=fork();
            if(id==0)
                    {
                          sleep(8);
                                  printf("i am child! pid:%d  ppid:%d\n",getpid(),getppid());
                                      }
                else if(id>0){
                        
                               printf("i am father!pid:%d ppid:%d\n",getpid(),getppid());
                                       }
                    else 
                            perror("fork false");
                        return 0;
}
