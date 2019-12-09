#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{

   ssize_t fd=open("text.txt",O_WRONLY|O_CREAT,0666);
   if(fd<0)
   {//dakai shibai
     printf("open false!\n");
     return;
   }
   else
   {
    dup2(3,1);
    char* ret="hello bit\n";
    write(fd,ret,strlen(ret));
    printf("fd:%d\n",fd);
   }
   close(fd);
   return 0;
}
