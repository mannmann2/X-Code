#include <iostream>
#define MAXSIZE 50

using namespace std;

class Stax
{
    int arr[MAXSIZE];
    int top;
    
public:
    Stax()
    {
        top=-1;
    }
    void Push();
    void Pop();
    void Peek();
    void display();
    
} obj;

void Stax::Push()
{
    if(top==MAXSIZE-1)
        cout<<"\nStack OVERFLOW\n";
    else
    {
        cout<<"Enter no. to be entered.\n";
        int x;
        cin>>x;
        top++;
        arr[top]=x;
    }
}

void Stax::Pop()
{
    if(top==-1)
        cout<<"\nStack UNDERFLOW\n";
    else
        top--;
}

void Stax::Peek()
{
    if(top==-1)
        cout<<"Stack UNDERFLOW\n\n";
    else
        cout<<"\nNumber at top is: "<<arr[top]<<endl;
}

void Stax:: display()
{
    cout<<"\nStack:\n";
    for(int i=top; i>=0; i--)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int ch;
    do
    {
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: obj.Push();
                break;
            
            case 2: obj.Pop();
                break;
                
            case 3: obj.Peek();
                break;
                
            case 4: exit(1);
                break;
                
            default: cout<<"Wrong Input. Try again.";
        }
        obj.display();
        cout<<endl;
    }
    while(ch!=4);
    return 0;
}

