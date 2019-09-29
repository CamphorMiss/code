#include"UdpServer.hpp"


void Explain(char *mes)
{
  cout<<"Please enter "<<mes<<" ip port "<<endl;
  exit(1);
}
int main(int argc,char *argv[])
{   
   // UdpServer s(argv[1],argv[2]);
    while(argc!=3)
    {//传参有问题
        Explain(argv[0]);
    }

   UdpServer s(argv[1],atoi(argv[2]));
    s.InitServer();
    s.RunServer();
    return 0;
}
