#include <iostream>

using namespace std;

struct tree
{
    int data;
    int used;
} node[100];


void build(int x)
{
    node[0].data=x;
    node[0].used=1;
    for(int i=1; i<100; i++)
        node[i].used=0;
}

void insert(int x)
{
    int p=0, q=0;
    while(q<100 && node[p].used)
    {
        q=p;
        if(x<node[p].data)
            p=q*2+1;
        else
            p=q*2+2;
    }
    node[p].data=x;
    node[p].used=1;
}

void display()
{
    cout<<"\n\n\nPos\tValue\n\n";
    for(int i=0; i<100; i++)
    {
        if(node[i].used==1)
            cout<<i<<"->\t\t"<<node[i].data<<endl;
    }
    
}

int main()
{
    int x;
    char ch;
    cout<<"Give a value for the root\n";
    cin>>x;
    build(x);
    cout<<"Enter more values?";
    cin>>ch;
    while(ch=='y')
    {
        cout<<"Provide value for next node\n";
        cin>>x;
        insert(x);
        cout<<"Enter more values?";
        cin>>ch;
    }
    display();

    return 0;
}

