#include<iostream>
#include<stdlib.h>

using namespace std;

struct Snake
{
    Snake *next;
    char *down;

} *front, *rear, *temp, *newnode;


char a[20][20];

int x,y;

void initial(char a[20][20]);
void display(char a[20][20]);
void apple(char a[20][20]);
void move(char a[20][20]);


int main()
{


    initial(a);

}


void initial(char a[20][20])
{
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            a[i][j]='.';
    
    a[1][1]='o';
    a[1][2]='*';
    
    front= new Snake;
    front->down=&a[1][2];
    
    rear= new Snake;
    rear->down=&a[1][1];
    
    rear->next=front;
    front->next=NULL;
    
    apple(a);
    display(a);
    move(a);
    
}


void apple(char a[20][20])
{
    x=rand()%19+1;
    y=rand()%19+1;
    if(a[x][y]=='.')
       a[x][y]='0';
    else
        apple(a);
    
}


void move(char a[20][20])
{
    char ch;
    
    cout<<"Enter\n";
    cin>>ch;
    
    for(int i=0; i<50; i++)
        cout<<endl;
    
    char *c;
    
    int i, j;
    
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            if(a[i][j]=='<')
            {
                x=i;
                y=j;
            }

    temp=rear;
    c=rear->down;
    
    while(temp->next!=front)
    {
        temp->down=(temp->next)->down;
        temp=temp->next;
    }
    
    temp->down=front->down;
    *front->down='o';
    switch(ch)
    {
        case 'w':
            if(x==0)
                front->down=&a[19][y];
            else
                front->down=&a[x-1][y];
            break;
    
        case 'a':
            if(y==0)
                front->down=&a[x][19];
            else
                front->down=&a[x][y-1];
            break;
    
        case 's':
            if(x==19)
                front->down=&a[0][y];
            else
                front->down=&a[x+1][y];
            break;
    
        case 'd':
            if(y==19)
                front->down=&a[x][0];
            else
                front->down=&a[x][y+1];
            break;
            
        default:;
            
    }
    
    
    if(*front->down!='o')
    {
        if(*front->down=='.')
            *c='.';
    
        else
        {
            apple(a);
            newnode=new Snake;
            newnode->down=c;
            *c='o';
            newnode->next=rear;
            rear=newnode;
        }
        *front->down='<';
        
        display(a);
        move(a);

    }
    
    else
        cout<<"GAME OVER!\n";
    
    
}


void display(char a[20][20])
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
            cout<<a[i][j]<<"\t";
        cout<<endl<<endl;
    }
}
