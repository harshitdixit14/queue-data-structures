#include <bits/stdc++.h>
using namespace std;
#define max_size 6
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
    return q->arr[item];
}
void push(Stack *s,int data)
{
    if(isempty(s->q2))
    {
        enqueue(s->q1,data);
    }
    else
        enqueue(s->q2,data);
}
int pop(Stack *s)
{
    int size1=(s->q1)->rear-(s->q1)->front+1;
    int size2=(s->q2)->rear-(s->q2)->front+1;
    int i=0;
    if(isempty(s->q2))
    {
        while(i<size1-1)
        {
            enqueue(s->q2,dequeue(s->q1));
            i++;
        }
        return dequeue(s->q1);
    }
    else
    {
        while(i<size2-1)
        {
            enqueue(s->q1,dequeue(s->q2));
            i++;
        }
        return dequeue(s->q2);
    }
}
int main()
{
    Stack *s=new Stack();
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    cout<<pop(s)<<endl;
    cout<<pop(s);
}