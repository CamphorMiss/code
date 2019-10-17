#include"Counter.hpp"

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
    local.sin_port=htons(8080);
    local.sin_addr.s_addr=inet_addr("127.0.0.1");
    while(1)
    {
    socklen_t len=sizeof(local);
    int ret1=connect(sock,(struct sockaddr *)&local,len);
    if(ret1<0)
    {
    cerr<<"connect fail..."<<endl;
    exit(2);
    }
    while(1)
    {
        Reques q;
       cout<<"please into op: (q--quit) ";
       cin>>q.op;
       if(q.op=='q')
           break;
       cout<<"please into two inter: ";
       cin>>q.x>>q.y;
       int ret2=send(sock,(void *)&q,sizeof(q),0);
       if(ret2<0)
       {
       cerr<<"send fail..."<<endl;
       exit(3);
       }
       Respons p;
       int ret3=recv(sock,(void *)&p,sizeof(p),0);
       if(ret3<0)
       {
       cerr<<"recv fail..."<<endl;
       exit(4);
       }
       cout<<"status:"<<p.status<<endl;
       cout<<"result:"<<p.result<<endl;
    }
    close(sock);
    }
    return 0;
}
