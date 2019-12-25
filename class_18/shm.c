#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/shm.h>
#define PATHNAME "."
#define PROJ_ID 0x4444
int main()
{
     
     int ret=shmget(ftok(PATHNAME,PROJ_ID),4096,IPC_CREAT|IPC_EXCL);
     if(ret==-1)
     {
     perror("shmget");
     return;
     }
     //连接到地址进程空间
   char *addr=(char *)shmat(ret,NULL,0);
     int i=0;
     while(i<26)
     {
    addr[i]='a'+i; 
    i++;
    addr[i]=0;
     sleep(1);
     }
     shmdt(addr);
      return 0;

}
