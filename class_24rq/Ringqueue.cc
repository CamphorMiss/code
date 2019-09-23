#include<iostream>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<semaphore.h>
#include<vector>
#include<pthread.h>
using namespace std;
class Rqueue{
private:
    vector<int>rq;
    int num;
    int p_step;
    int c_step;
    sem_t p_sem;
    sem_t c_sem;
public:
  Rqueue(int _num=1024):num(_num),rq(_num)
  {
      p_step=0;
      c_step=0;
     
      sem_init(&p_sem,0,4);
      sem_init(&c_sem,0,0);
  }
  void P(sem_t *sem)
  {
      sem_wait(sem);
  }
  void V(sem_t* sem)
  {
      sem_post(sem);
  }
  void PopData(int &data)
  {
    P(&c_sem);
    data= rq[c_step];
    c_step++;
    c_step%=num;
    V(&p_sem);

  }
  void PushData(int &data)
  {
      P(&p_sem);
      rq[p_step]=data;
      p_step++;
      p_step%=num;
      V(&c_sem);
  }
  ~Rqueue()
  {
      sem_destroy(&p_sem);
      sem_destroy(&c_sem);
  }

};
void *consumer(void *arg)
{
   Rqueue *q=(Rqueue *)arg;
   while(1)
   {
    int data;
    q->PopData(data);
    cout<<"consumer data is :"<<data<<endl;
    sleep(1);
   }
}
void *productor(void *arg)
{
    Rqueue *q=(Rqueue *)arg;
  while(1)
  {
    int data=rand()%100+1;
    q->PushData(data);
    cout<<"productor  data is :"<<data<<endl;
  }
}
int main()
{
  Rqueue r(5);
  pthread_t  p1,p2;
  srand((unsigned long)time(NULL));
  pthread_create(&p1,NULL,consumer,(void *)&r);
  pthread_create(&p2,NULL,productor,(void *)&r);
  pthread_join(p1,NULL);
  pthread_join(p2,NULL);
  
  return 0;
}
