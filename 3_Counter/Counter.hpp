#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
using namespace std;
typedef struct Reques
{
    int x;
    int y;
    char op;//caizoufu
}Reques;
typedef struct Respons
{
    int status;
    int result;
}Respons;

