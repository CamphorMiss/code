#include<iostream>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
class BlockQueue
{
private:
    queue<int> q;//super
    int cap;
    pthread_mutex_t lock;
    pthread_cond_t p_cond;
    pthread_cond_t c_cond;

public:
    BlockQueue(int _cap=10):cap(_cap)
    {
        phtread_mutex_init(&lock,NULL);
        pthread_cond_init(&p_cond,NULL);
        pthread_cond_init(&c_cond,NULL);
    }
    ~BlockQueue()
    {
        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&p_cond);
        pthread_cond_destroy(&c_cond);
    }
    void Popdata(int &data)
    {
        if(q.size()!=0)
        {
           
        }

    }
    void Pushdata(const int &data)
    {
    }


};
void *consumer(void *arg)
{
    BlockQueue *que=(BlockQueue *)arg;
    int val;
    while(1)
    {
    que->Popdata(val);
    cout<<"Consumer val is "<<val<<endl;
    sleep(1);
    }
}
void *producter(void *arg)
{
    BlockQueue *que=(BlockQueue *)arg;
    int val;
    while(1)
    {
    val= rand()%100;
    que->Pushdata(val);
    cout<<"producter val is "<<val<<endl;
    }
}
int main()
{

    BlockQueue bq;
    srand((unsign long)time(NULL));
    pthread_t p1,p2;
    pthread_create(&p1,NULL,consumer,(void *)&bq);
    pthread_create(&p2,NULL,producter,(void *)&bq);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    return 0;
}
