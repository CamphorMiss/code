#include<stdio.h>
#include<unistd.h>
#include<string.h>
int  main()
{
  int i=0;int j=0;
const char arr[3][3]={" | ","- -"," | "};
for(;i<10000;i++)
{
for(j;j<10000;j++)
{
printf("[%c]\r",arr[i%3][j%3]);
fflush(stdout);
usleep(10000);
}
}
printf("\n");
return 0;
}
