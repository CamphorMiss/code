#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/shm.h>
#define PATHNAME "."
#define PROJ_ID 0x4444
int main()
{
    int ret= shmget(ftok(PATHNAME,PROJ_ID),4096,0);
     //连接到地址进程空间
    char *addr=(char *)shmat(ret,NULL,0);
     int i=26;
     while(i--)
     {
     printf("shm:%s\n",addr);
     sleep(1);
     }
     shmdt(addr);
      return 0;

}
