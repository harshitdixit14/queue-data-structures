#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
};
class queue_LL{
public:
    node *front;
    node *rear;
};
queue_LL *create_queue_LL()
{
    queue_LL *new_queue=new queue_LL();
    new_queue->front=NULL;
    new_queue->rear=NULL;
    return new_queue;
}
int isempty(queue_LL *q1)
{
    return (q1->front==NULL)?1:0;
}
void enqueue(queue_LL *q1,int val)
{
    node *new_node=new node();
    node *temp=q1->rear;
    new_node->data=val;
    if(q1->front==NULL && q1->rear==NULL)
    {
        q1->front=new_node;
        q1->rear=new_node;
        new_node->next=NULL;
    }
    else
    {
        temp->next=new_node;
        q1->rear=new_node;
    }
}
void dequeue(queue_LL *q1)
{
    if(isempty(q1))
    {
        cout<<"underflow error!!";
    }
    node *temp=q1->front;
    q1->front=temp->next;
    delete temp;
}
void traverse_queue_LL(queue_LL *q1)
{
    while(q1->front!=NULL)
    {
        cout<<(q1->front)->data<<" ";
        q1->front=(q1->front)->next;
    }
}
void delete_queue(queue_LL *q1)
{
    if(q1->front==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    while(q1->front!=NULL)
    {
        node *temp=q1->front;
        q1->front=temp->next;
        delete temp;
    }
}
int main()
{
    queue_LL *q1=create_queue_LL();
    enqueue(q1,10);
    enqueue(q1,20);
    enqueue(q1,30);
    enqueue(q1,40);
    dequeue(q1);
    dequeue(q1);
    traverse_queue_LL(q1);
    delete_queue(q1);
    traverse_queue_LL(q1);
}