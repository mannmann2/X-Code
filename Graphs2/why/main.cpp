#include <iostream>

using namespace std;

struct edge;

struct node
{
    int info;
    node *next;
    edge *adj;
} *start;

struct edge
{
    node *dest;
    edge *link;
};

int n;

void buildlist()
{
    node *curr, *prev;
    cout<<"Enter no. of nodes in graph\n";
    cin>>n;
    prev=NULL;
    for(int i=1; i<=n; i++)
    {
        curr=new node;
        curr->next=NULL;
        curr->adj=NULL;
        curr->info=i;
        if(prev==NULL)
            start=curr;
        else
            prev->next=curr;
        prev=curr;
    }
}

void insertedges()
{
    edge *curr, *prev;
    node *temp, *ptr;
    
    int k, m, p;
    temp=start;
    
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter no. of adjacent edges for node "<<i<<endl;
        cin>>m;
        prev=NULL;
        for(int j=1; j<=m; j++)
        {
            cout<<"Enter value for adjacent node "<<j<<endl;
            cin>>k;
            curr=new edge;
            ptr=start;
            curr->link= NULL;
            p=1;
            while(p<k)
            {
                ptr=ptr->next;
                p++;
            }
                curr->dest=ptr;
                if(prev==NULL)
                    temp->adj=curr;
                else
                    prev->link=curr;
                temp=temp->next;
        }
    }
}

void display()
{
    cout<<"\n\n\n";
    node *node;
    edge *ptr, *curr;
    node=start;
    while(node!=NULL)
    {
        cout<<node->info;
        curr=node->adj;
        while(curr->link!=NULL)
        {
            ptr=curr;
            cout<<ptr->dest->info;
            curr=curr->link;
        }
        node=node->next;
    }
}

int main()
{
    buildlist();
    insertedges();
    display();
    return 0;
}

