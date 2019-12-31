#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define STATE1 0
#define STATE2 1
#define STATE3 2
#define STATETRAP 3
#define STATENUM 4
#define CONDITION1 0
#define CONDITION2 1
#define CONDITIONS 2
typedef void (* actiontype)(int myint,int myint);
typedef struct{
      int next;
        actiontype action;
}trasition, *ptrasition;

void action1(int myint,int myconditon);
void action2(int myint,int myconditon);
void action3(int myint,int myconditon);
void actiontrap(int myint,int myconditon);
trasition t1={
      STATE2,action1
};
trasition t2={
      STATE3,action2
};
trasition t3={
      STATE2,action3
};
trasition tt={
      STATETRAP,actiontrap
};

void action1(int myint,int myconditon){
      printf("action1 one triggered\n");
}
void action2(int myint,int myconditon){
      printf("action2 one triggered\n");
}
void action3(int myint,int myconditon){
      printf("action3 one triggered\n");
}
void actiontrap(int myint,int myconditon){
      printf("actiontrap one triggered\n");
}

ptrasition transition_table[STATENUM][CONDITIONS] = {
    /*      c1,  c2*/
    /* s1 */&t1, &tt,
    /* s2 */&tt, &t2,
    /* s3 */&t3, &tt,
    /* st */&tt, &tt,
};
typedef struct
{
        int current;
} StateMachine, * pStateMachine;
 
int step(pStateMachine machine, int myint)
{
        ptrasition t = transition_table[machine->current][myint];
            (*(t->action))(machine->current, myint);
                machine->current = t->next;
                    printf("the current int is %d\n",t->next );
                        return machine->current;
}
int main(int argc, char *argv[])
{
      StateMachine mymachine;
        mymachine.current=STATE1;
          int mycon;
            char ch;
              while(1){
                      scanf("%d",&mycon); 
                          step(&mymachine,mycon);
                            }
                return 0;
}
