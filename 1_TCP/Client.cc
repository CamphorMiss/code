#include"TcpClient.hpp"

int main()
{
    Client* C=new (Client);
    C->InitClient();
    C->StarClient();
    delete C;
    C=NULL;
    return 0;
}
