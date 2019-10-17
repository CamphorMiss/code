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
    local.sin_addr.s_addr=htonl(INADDR_ANY);
    local.sin_port=htons(8080);
    int ret1=bind(sock,(struct sockaddr *)&local,sizeof(local));
    if(ret1<0)
    {
    cerr<<"bind fail..."<<endl;
    exit(2);
    }
    int ret2=listen(sock,6);
    if(ret2<0)
    {
    cerr<<"listen fail..."<<endl;
    exit(3);
    }
    struct sockaddr_in peer;
    while(1)
    {
    socklen_t len=sizeof(peer);
    int onesock=accept(sock,(struct sockaddr *)&peer,&len);
    if(onesock<0)
    {
    cerr<<"accept fail..."<<endl;
    continue;
    }
    cout<<"Get a new line..."<<endl;
   while(1)
   {
    Reques q;
    int ret3=recv(onesock,(void *)&q,sizeof(q),0);
    if(ret3==0)
    {
    cerr<<"Client close..."<<endl;
    exit(4);
    }
    if(ret3<0)
    {
    cerr<<"revc fail..."<<endl;
    exit(5);
    }

    Respons p={0,0};
    switch(q.op)
    {
        case '+':p.result=q.x+q.y;
            break;
        case '-':p.result=q.x-q.y;
                 break;
        case '*':p.result=q.x*q.y;
                 break;
        case '/':if(q.y==0)
                     p.status=1;
                 else 
                     p.result=q.x/q.y;
                 break;
        case '%':if(q.y==0)
                     p.status=2;
                 else
                     p.result=q.x%q.y;
                 break;
        default:p.status=3;
                break;
}
send(onesock,(void *)&p,sizeof(p),0);
}
close(onesock);
}
//close(onesock);
//close(onesock);
    return 0;
}
