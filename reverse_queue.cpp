#include <iostream>
using namespace std;
#define max_size 5
#define MAXSIZE 13
class queue{
public:
    int front,rear;
    int capacity;
    int *array;
};
class stack_array{
public:
    int top;
    int capacity;
    int *array1;
};
int isEmpty(stack_array *s1)
{
    if(s1->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(stack_array *s1)
{
    if(s1->top==s1->capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
stack_array* create_stack()
{
    stack_array* S=new stack_array();
    S->capacity=MAXSIZE;
    S->top=-1;
    S->array1=(int*)malloc(S->capacity*sizeof(int));
    return S;
}
void push(stack_array *s1,int data)
{
    if(isFull(s1))
    {
        cout<<"STACK OVERFLOW";
    }
    else{
    s1->top++;
    s1->array1[s1->top]=data;
    }
}
void pop(stack_array *s1)
{
    if(isEmpty(s1))
    {
        cout<<"STACK EMPTY";
    }
    else
    {
        --s1->top;
    }
}
void traverse(stack_array *s1)
{
    while((s1->top)!=-1)
    {
        cout<<s1->array1[s1->top]<<" ";
        --(s1->top);
    }
}
queue *create_queue()
{
    queue *Q=new queue();
    Q->front=-1;
    Q->rear=-1;
    Q->array=(int*)malloc(max_size*sizeof(int));
    Q->capacity=max_size;
    return Q;
}
int queue_size(queue *Q)
{
    return (Q->rear)-(Q->front)+1;
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
    int i=Q->front;
    while(i!=Q->rear+1)
    {
        cout<<Q->array[i]<<" ";
        i+=1;
    }
}
void reverse_queue(stack_array *s,queue *q)
{
    int data;
    while(q->front!=q->rear+1)
    {
        data=q->array[q->front];
        push(s,data);
        q->front++;
    }
}
int main()
{
    queue *Q=create_queue();
    enqueue(Q,10);
    enqueue(Q,20);
    enqueue(Q,30);
    cout<<"queue before reversing : ";
    traverse_queue(Q);
    cout<<endl;
    stack_array *s=create_stack();
    cout<<"queue after reversing : ";
    reverse_queue(s,Q);
    traverse(s);
}