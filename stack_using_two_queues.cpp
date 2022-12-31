#include <bits/stdc++.h>
using namespace std;
#define max_size 5
class Queue{
public:
    int front;
    int rear;
    int *arr;
};
Queue *create_queue()
{
    Queue *q=new Queue();
    q->front=-1;
    q->rear=-1;
    q->arr=(int*)malloc(max_size*sizeof(int));
    return q;
}
class Stack{
public:
    Queue *q1=create_queue();
    Queue *q2=create_queue();
};
int isempty(Queue *q)
{
    if(q->front==-1 && q->rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(Queue *q)
{
    if(q->front+1==max_size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(Queue *q,int data)
{
    if(isfull(q))
    {
        cout<<"overflow";
    }
    else
    {
        if(q->front==-1 && q->rear==-1)
        {
            q->front=0;
            q->rear=0;
        }
        else
        {
            q->rear=(q->rear+1)%max_size;
        }
        q->arr[q->rear]=data;
    }
}
int dequeue(Queue *q)
{
    int item=q->front;
    if(isempty(q))
    {
        cout<<"underflow";
    }
    else
    {
        q->front=(q->front+1)%max_size;
    }
    return item;
}
void push(Stack *s,int data)
{
    if(isempty(s->q1))
    {
        enqueue(s->q2,data);
    }
    else
        enqueue(s->q1,data);
}
int pop(Stack *s)
{
    int value=dequeue(s->q1);
    int i;
    if(isempty(s->q2))
    {
        i=(s->q1)->front;
        while(i<(s->q1)->rear-1)
        {
            enqueue(s->q2,dequeue(s->q1));
            i++;
        }
    }
    return dequeue(s->q1);
}
int main()
{
    Stack *s=new Stack();
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    cout<<pop(s);
}