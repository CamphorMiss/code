#include<iostream>
#include<map>
#include<unistd.h>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
using namespace std;
map<string,string>m;//{{"apple","苹果"},{"banana","香蕉"},{"orange","橙子"},{"grape","葡萄"}};
void ServerIO(int sock)
{ 
   while(1)
   {
   char word[1024];
   string result;
   int ret1= recv(sock,word,sizeof(word),0);
   if(ret1<0)
   {
   cerr<<"recv fail..."<<endl;
   exit(6);
   }
   else if(ret1==0)
   {
   cerr<<"Client Close..."<<endl;
   break;
   }
   else
   {//success
       string s(word);
   if(m.find(s)==m.end())
   {
   result="Unknow";
   }
   else
       result=(m.find(s))->second;
   send(sock,result.c_str(),sizeof(result),0);
   }
   }
   close(sock);
}
int main()
{

    m.insert(make_pair("apple","苹果"));
    m.insert(make_pair("banana","香蕉"));
    m.insert(make_pair("orange","橙子"));
    m.insert(make_pair("grape","葡萄"));
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0)
    {
    cerr<<"socket fail..."<<endl;
    exit(1);
    }
    struct sockaddr_in local;
    local.sin_family=AF_INET;
    local.sin_addr.s_addr=htonl(INADDR_ANY);
    local.sin_port=htons(8080);
    socklen_t len1=sizeof(local);
    int num1=bind(sock,(struct sockaddr *)&local,len1);
    if(num1<0)
    {
    cerr<<"bind fail..."<<endl;
    exit(2);
    }
    int num2=listen(sock,6);
    if(num2<0)
    {
    cerr<<"listen fail..."<<endl;
    exit(3);
    }
    while(1)
    {
    struct sockaddr_in peer;
    socklen_t len2=sizeof(peer);
    int onesock=accept(sock,(struct sockaddr *)&peer,&len2);
    if(onesock<0)
    continue;
    cout<<"Get a new line..."<<endl;
    ServerIO(onesock);
    }
    close(sock);
    return 0;
}
