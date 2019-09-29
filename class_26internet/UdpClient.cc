#include"UdpClient.hpp"


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

   UdpClient c(argv[1],atoi(argv[2]));
    c.InitClient();
    c.RunClient();
    return 0;
}
