#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;
class Server
{
private:
    int listen_sock;
    int sock;
    string ip;
    int port;
public:
    Server(string _ip="127.0.0.1",int _port=8080):ip(_ip),port(_port)
    {
        listen_sock=-1;
        sock=-1;
    }
    void InitServer()
    {
    listen_sock=socket(AF_INET,SOCK_STREAM,0);
    if(listen_sock<0)
    {
       cerr<<"socket fail..."<<endl;
       exit(2);
    }
    struct sockaddr_in local;
    local.sin_family=AF_INET;
    local.sin_port=htons(port);
    local.sin_addr.s_addr=inet_addr(ip.c_str());

   if(bind(listen_sock,(struct sockaddr *)&local,sizeof(local))<0)
           {
               cerr<<"bind fail..."<<endl;
               exit(3);
           }
     //   int t=connect(listen_sock,(struct sockaddr *)&local,sizeof(local));
     //   if(t<0);
     //   {
     //    cerr<<"connect fail..."<<t<<endl;
     //    exit(5);
     //   }
    }
    void StarServer()
    {
     //走到这里，创建，绑定，监听,连接都成功了。
     //开始接受连接
     if(listen(listen_sock,10)<0)
     {
          cerr<<"listen fail..."<<endl;
           exit(4);
     }
     struct sockaddr_in perr;
     socklen_t temp=0;
     sock=accept(listen_sock,(struct sockaddr *)&perr,&temp);//带回型参数
     if(sock<0)
     {
         cerr<<"accept fail..."<<endl;
         exit(10);
     }
     char buf[1024];
     while(1)
     {
     bzero((void *)&buf,sizeof(buf));
     int l=read(sock,buf,sizeof(buf));
     if(l<0)
     {
      cerr<<"Write Close..."<<endl;
      exit(5);
     }
     buf[l]=0;
     cout<<"Client# "<<buf<<endl;
     write(sock,buf,strlen(buf));
    }
    }
    ~Server()
    {
        if(listen_sock>0)
        {
            close(listen_sock);
        }
    }
};
