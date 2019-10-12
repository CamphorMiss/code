#include"TcpServer.hpp"

int main()
{
    Server* S=new (Server);
    S->InitServer();
    S->StarServer();
    delete S;
    S=NULL;
    return 0;
}
