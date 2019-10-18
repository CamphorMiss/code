#include<iostream>
#include<map>
#include<unistd.h>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
using namespace std;
int main()
{
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
    {
    cerr<<"socket fail..."<<endl;
    exit(1);
    }
    struct sockaddr_in local;
    local.sin_family=AF_INET;
    local.sin_addr.s_addr=inet_addr("127.0.0.1");
    local.sin_port=htons(8080);
    int len=sizeof(local);
    int ret=connect(sock,(struct sockaddr*)&local,len);
    if(ret<0)
    {
    cerr<<"connect fail..."<<endl;
    exit(2);
    }
    while(1)
    {
    string mas;
    cout<<"Please into word: ";
    cin>>mas;
    int ret2=send(sock,(void *)mas.c_str(),sizeof(mas),0);
    if(ret2<0)
    {
    cerr<<"send fail..."<<endl;
    exit(3);
    }
    char result[1024];
    int ret3=recv(sock,result,sizeof(result),0);
    if(ret3<0)
    {
    cerr<<"recv fail..."<<endl;
    exit(4);
    }
    cout<<result<<endl;
    }
    close(sock);
    return 0;
}
