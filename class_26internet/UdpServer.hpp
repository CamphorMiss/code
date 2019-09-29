#pragma once

#include<arpa/inet.h>
#include<iostream>
#include<unistd.h>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

class UdpServer
{
    private:
        int sock;
        string udps_ip;
        int udps_port;
    public:
    UdpServer(string _ip="192.0.0.1",int _port=8080):udps_ip(_ip),udps_port(_port)
    {
      sock=-1;
    }
    void InitServer()
    {
        sock=socket(AF_INET,SOCK_DGRAM,0);
        if(sock<0){
        cerr<<"socket err!"<<endl;
        exit(1);
        }
        else
        {//成功则返回网卡的文件描述符
        //创建成功则绑定端口号
        struct sockaddr_in addr;
        addr.sin_family=AF_INET;
        addr.sin_port=htons(udps_port);
        addr.sin_addr.s_addr=inet_addr(udps_ip.c_str());

        int ret=bind(sock,(struct sockaddr *)&addr,sizeof(addr));
        if(ret<0)
        {//绑定失败
         cerr<<"bind err!"<<endl;
            exit(2);
        }
        if(ret==0)
        {
        cout<<"绑定成功！"<<endl;
        }
    }
    }
    void RunServer()
    {

        //  int i=0;
        char buf[1024];
        while(1)
        {
           //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
           //struct sockaddr *src_addr, socklen_t *addrlen);
          struct sockaddr_in addr;
          addr.sin_family=AF_INET;
          addr.sin_port=ntohs(udps_port);
          addr.sin_addr.s_addr=inet_addr(udps_ip.c_str());
          socklen_t _l=sizeof(addr);

       //    char buf[1024];
          int _len=recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr *)&addr,&_l);
      if(_len<0)
      {
       cerr<<"recvfrom err!"<<endl;
       exit(3);
      }
      else
      {//收到的字节数
          buf[_len]=0;
          // ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                   //const struct sockaddr *dest_addr, socklen_t addrlen);
           cout<<"Clent # "<<buf<<endl;
           sleep(1);
         // string arr[1024]={"你好鸭！","我叫王五","我在睡觉","再见！"};
        //  int i=0;
          struct sockaddr_in addr;
                   addr.sin_family=AF_INET;
                   addr.sin_port=htons(udps_port);
                   addr.sin_addr.s_addr=inet_addr(udps_ip.c_str());
                   socklen_t _l=sizeof(addr);

      sendto(sock,buf,_len,0,(struct sockaddr*)&addr,_l);
       }

          //   int _len= read(sock,buf,sizeof(buf));
       //    if(_len<0)
       //    {
       //    cerr<<"read err!"<<endl;
       //    exit(3);
       //    }
       //    else
       //    {
       //        buf[_len]=0;
       //        int _size=write(sock,buf,sizeof(buf)-1);
       //        if(_size<0)
       //        {
       //        cerr<<"write err!"<<endl;
       //        exit(4);
       //        }
       //        if else(_size==0)
       //        {
       //        cerr<<"Client Close!"<<endl;
       //        exit(5);
       //        }
       //        else
       //        {
       //         cerr<<"Client speak # "<<buf<<endl;
       //        }
       //    }
        }
    }
    ~UdpServer()
    {
    }
};
