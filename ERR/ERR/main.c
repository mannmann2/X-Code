#include<stdio.h>
#include<stdlib.h>
struct list_node
{
    int info;
    struct list_node *next;
};
void Create(struct list_node *);
void Insert_Begin(struct list_node *);
void Insert_End(struct list_node *);
void Display(struct list_node *);
struct list_node *start;
struct list_node *rear;


int main()
{
    struct list_node *node, *start; char c = '1';
    node = (struct list_node *)malloc(sizeof(struct list_node));
    if (node == NULL)
    {
        printf("\n No Space in Memory \n");
        return 0;
    }
    Create(node);
    //start = node;
    while(c != '3')
    {
        printf("\n  1. Insert at the beginning \n");
        printf("\n  2. Insert at the End \n");
        printf("\n  3. Display \n");
        printf("\n  4. Quit \n");fflush(stdin);
        scanf("%c", &c);
        switch(c)
        {
            case '1': Insert_Begin(node);node = start; start = NULL;
                break;
                
            case '2': Insert_End(node);
                break;
                
            case '3': Display(node);
                break;
                
            case '4': break;
                
            default: break;
        }
    }
    //getch();
}

void Create(struct list_node *node)
{
    struct list_node *newnode;
    char ch; int i=1;
    printf("\n Enter Value for Node %d \n",i);
    scanf("%d", &node->info); i++;
    node->next = NULL;
    
    while (ch != 'n')
    {
        newnode = (struct list_node *)malloc(sizeof(struct list_node));
        printf("\n Enter Value for node %d \n", i);
        scanf("%d", &newnode->info);i++;
        newnode->next = NULL;
        node->next = newnode;
        node = newnode;
        
        printf(" \n Press 'n' to quit, any other key to continue \n"); fflush(stdin);
        ch = getchar();
    }
}

void Display( struct list_node *node)
{
    printf(" \n Values of Nodes are \n");
    while(node != NULL)
    {
        printf("%d  ", node->info);
        node = node->next;
    }
}

void Insert_Begin(struct list_node *node)
{
    struct list_node *curr;
    curr = (struct list_node *)malloc(sizeof(struct list_node));
    printf("\n Enter Value for Node \n");
    scanf("%d", &curr->info);
    //newnode->next = NULL;
    curr->next = node;
    start = curr;
    
}

void Insert_End(struct list_node *node)
{
    struct list_node *curr;
    curr = (struct list_node *)malloc(sizeof(struct list_node));
    printf("\n Enter Value for Node \n");
    scanf("%d", &curr->info);
    if(start==NULL)
        start=rear=curr;
    else
    {
        rear->next=curr;
        rear=curr;
    }
}
