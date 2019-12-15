#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
fork();
cout<<getpid()<<"hello liujiawei~"<<endl;

return 0;
}

