#include <iostream>
using namespace std;
#define max_size 5
class queue{
public:
    int front,rear;
    int capacity;
    int *array;
};
queue *create_queue()
{
    queue *Q=new queue();
    Q->front=-1;
    Q->rear=-1;
    Q->array=(int*)malloc(max_size*sizeof(int));
    Q->capacity=max_size;
    return Q;
}
int isempty(queue *Q)
{
    return (Q->front==-1)?1:0;
}
int isfull(queue *Q)
{
    return (((Q->rear+1)%Q->capacity)==Q->front)?1:0;
}
void enqueue(queue *Q,int item)
{
    if(isfull(Q))
    {
        cout<<"overflow error!!"; 
    }
    else
    {
        if(Q->front==-1)
        {
            Q->front=Q->rear+1;
        }
        Q->array[(Q->rear+1)%(Q->capacity)]=item;
        Q->rear+=1;
    }
}
void dequeue(queue *Q)
{
    int data;
    if(isempty(Q))
    {
        cout<<"underflow error!!";
    }
    else
    {
        if(Q->front==Q->rear)
        {
            Q->front=-1;
            Q->rear=-1;
        }
        else
        {
            data=Q->array[Q->front%Q->capacity];
            Q->front=(Q->front+1)%Q->capacity;
        }
    }
    cout<<"data deleted is: "<<data;
}
void traverse_queue(queue *Q)
{
    while(Q->front!=Q->rear+1)
    {
        cout<<Q->array[Q->front]<<" ";
        Q->front+=1;
    }
}
int main()
{
    queue *Q=create_queue();
    enqueue(Q,10);
    enqueue(Q,20);
    enqueue(Q,30);
    enqueue(Q,40);
    enqueue(Q,50);
    enqueue(Q,60);
    traverse_queue(Q);
    dequeue(Q);
    cout<<endl;
    cout<<"resultant queue is"<<endl;
    traverse_queue(Q);
}