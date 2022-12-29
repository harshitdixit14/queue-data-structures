//implement queue using two stacks
//in this we will use two stacks
#include <iostream>
using namespace std;
#define MAXSIZE 13
class stack_array{
public:
    int top;
    int capacity;
    int *array;
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
    S->array=(int*)malloc(S->capacity*sizeof(int));
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
    s1->array[s1->top]=data;
    }
}
int pop(stack_array *s1)
{
    int data;
    if(isEmpty(s1))
    {
        cout<<"STACK EMPTY";
    }
    else
    {
        data=s1->array[s1->top];
        --s1->top;
    }
    return data;
}
void traverse(stack_array *s1)
{
    while((s1->top)!=-1)
    {
        cout<<s1->array[s1->top]<<" ";
        --(s1->top);
    }
}
void delete_stack(stack_array *s1)
{
    delete s1->array;
}
class queue{
public:
    stack_array *s1=create_stack();// this stack for enqueue operations
    stack_array *s2=create_stack();// this for dequeue operations
};
void enqueue(queue *q1,int data)
{
    push(q1->s1,data);
}
int dequeue(queue *q1)
{
    while((q1->s1)->top!=-1)
    {
        push(q1->s2,pop(q1->s1));
    }
    return pop(q1->s2);
}
int main()
{
    queue *q1=new queue();
    enqueue(q1,12);
    enqueue(q1,34);
    enqueue(q1,45);
    enqueue(q1,89);
    cout<<dequeue(q1)<<endl;
    cout<<dequeue(q1);
}