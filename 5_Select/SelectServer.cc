#include"SelectServer.hpp"

int main(int arc,char* argv[])
{
    if(arc!=2)
    {
    cout<<"Uage:"<<argv[0]<<"port "<<endl;
    exit(1);
    }
    SelectServer* s=new SelectServer(argv[1]);
    s->InitServer();
    s->RunServer();
    return 0;
    
}
