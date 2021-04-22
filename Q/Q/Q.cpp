#include <iostream>
#define MAXSIZE 50
using namespace std;
class Queue
{
    int arr[MAXSIZE];
    int front, rear;
    
public:
    Queue()
    {
        front=0;
        rear=-1;
    }
    int isFull();
    int isEmpty();
    void enQ(int x);
    int deQ();
    void display();

} p;

int Queue::isFull()
{
    if(rear==MAXSIZE-1)
        return 1;
    else
        return 0;
}

int Queue::isEmpty()
{
    if(rear<front)
        return 1;
    else
        return 0;
}

void Queue::enQ(int x)
{
    if(isFull())
    {
        cout<<"Queue is full.\n\n";
    }
    rear++;
    arr[rear]=x;
}

int Queue::deQ()
{
    if(isEmpty())
    {
        cout<<"Queue is empty. Try entering some elements.\n\n";
    }
    front++;
    return arr[front-1];
}

void Queue::display()
{
    cout<<"Queue==>  ";
    for(int i= front; i<=rear; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n";
}

int main()
{
    int ch;
    int x;
    while(ch!=3)
    {
        cout<<"1. Insert\n2. Delete\n3. Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the number to be entered.\n";
                cin>>x;
                p.enQ(x);
                break;
            
            case 2: p.deQ();
                break;
            
            case 3: exit(1);
            
            default: cout<<"Wrong Input. Try again.\n";
        }
        
        p.display();
    }
    return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
