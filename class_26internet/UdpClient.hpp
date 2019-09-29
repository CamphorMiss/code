#pragma once
#include<arpa/inet.h>
#include<iostream>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
#include<cstring>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

class UdpClient
{
    private:
        int sock;
        string udpc_ip;
        int udpc_port;
    public:

    UdpClient(string _ip="192.0.0.1",int _port=8080):udpc_ip(_ip),udpc_port(_port)
    {
      sock=-1;
    }
    void InitClient()
    {
        sock=socket(AF_INET,SOCK_DGRAM,0);
        if(sock<0){
        cerr<<"socket err!"<<endl;
        exit(1);
        }
    }  
    void RunClient()
    {  
                           char buf[1024];
                            struct sockaddr_in addr;
                              addr.sin_family=AF_INET;
                               addr.sin_port=htons(udpc_port);
                                addr.sin_addr.s_addr=inet_addr(udpc_ip.c_str());
                             socklen_t _l=sizeof(addr);
                             while(1)
                             {
                             string mes;
                             cout<<"Please enter# ";
                             cin>>mes;
        int ss=sendto(sock,mes.c_str(),mes.size(),0,(struct sockaddr *)&addr,_l);
            // cout<<"发送的长度 "<<ss<<endl;
                            // char * buf[1024];
           //ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
           //struct sockaddr *src_addr, socklen_t *addrlen);
         if(ss>0)
         {
         struct sockaddr_in peer;
          peer.sin_family=AF_INET;
          peer.sin_port=ntohs(udpc_port);
          peer.sin_addr.s_addr=inet_addr(udpc_ip.c_str());
          socklen_t _l=sizeof(peer);
          int _len= recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr *)&peer,&_l);
          cout<<"接收的长度 "<<_len<<endl;
      if(_len<0)
      {
       cerr<<"recvfrom err!"<<endl;
       exit(3);
      }
      else
      {
          buf[_len]=0;
          cout<<"Server #"<<buf<<endl;
          sleep(1);
        //   struct sockaddr_in addr;
        //           addr.sin_family=AF_INET;
        //           addr.sin_port=htons(client_port);
        //           addr.sin_addr.s_addr=inet_addr(client_ip.c_str());
        //           int _l=sizeof(addr);

        //  sendto(sock,arr[i++].c_str,arr[i++].size(),AF_INET,(struct sockaddr_in *)&addr,&_l);
       
        }
         }
    }
    }
    ~UdpClient()
    {
    }
};
