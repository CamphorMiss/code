#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{//先从键盘读数据，存入buf，再写入管道，从管道再读取，写入屏幕，你写我读
   int fd[2];
   char buf[1024];
   int id=pipe(fd);//创建一个管道，有可能失败
   if(id==-1)
   {
   perror("pipe");
   }
   //创建成功了，从输入端读
   while(fgets(buf,100,stdin))
   {
       int len=strlen(buf);
       //写进管道
       if(write(fd[1],buf,len)!=len)
       {
         perror("write into pipe");
         break;
       }
       memset(buf,0x00,sizeof(buf));

       //从管道读
       if(read(fd[0],buf,100)==0)
       {
       perror("read into pipe");
       break;
       }

       //写到屏幕
       if(write(1,buf,len)!=len)
       {
       perror("write into stdout");
       break;
       }
 }
   return 0;
}
