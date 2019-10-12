#include<iostream>
#include<stdlib.h>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
using namespace std;

class Client
{
    private:
        int sock;
        string ip;
        int port;
    public:
        Client(string _ip="127.0.0.1",int _port=8080):ip(_ip),port(_port)
        {
          sock=-1;
        }
        void InitClient()
        {
           sock= socket(AF_INET,SOCK_STREAM,0);
           if(sock<0)
           {
           cerr<<"socket fail..."<<endl;
           exit(7);
           }
        }
        void StarClient()
        {
            struct sockaddr_in local;
            local.sin_family=AF_INET;
            local.sin_addr.s_addr=inet_addr(ip.c_str());
            local.sin_port=htons(port);
            int ret=connect(sock,(struct sockaddr *)&local,sizeof(local));
            if(ret<0)
            {
                 cerr<<"connect fail..."<<endl;
                  exit(8);
            }

            while(1)
            {
                
                string mas;
                char buf[1024]={0};
                cout<<"Please enter :";
                cin>>mas;
                write(sock,mas.c_str(),mas.size());
                int l=read(sock,buf,sizeof(buf));
                if(l<0)
                {
                  cerr<<"Server Close..."<<endl;
                  exit(9);
                }
                buf[l]=0;
                cout<<"Server# "<<buf<<endl;
        }
        }
        ~Client()
        {
         if(sock>0)
         {
         close(sock);
         }
        }

};
