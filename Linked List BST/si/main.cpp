#include<iostream>

using namespace std;

struct tree
{
    int data;
    tree *left, *right;
}*node;


tree* min(tree *node)
{
    while(node->left!=NULL)
        node=node->left;
    return node;
}

tree* insert(tree *node, int x)
{
    if(node==NULL)
    {
        node= new tree;
        node->data=x;
        node->left=node->right=NULL;
    }
    
    else if(x<node->data)
        node->left=insert(node->left, x);
    
    else
        node->right=insert(node->right, x);
    
    return node;
}


tree* remove(tree *node, int x)
{
    tree *temp;
    if(x<node->data)
        node->left=remove(node->left, x);
    
    else if (x>node->data)
        node->right=remove(node->right, x);
    
    else if((node->right) && (node->left))
    {
        temp=min(node->right);
        node->data=temp->data;
        node->right=remove(node->right, temp->data);
    }
    else
    {
        temp=node;
        if(node->right==NULL)
            node=node->left;
        else if(node->left==NULL)
            node=node->right;
        
        free(temp);
    }
    return node;
}


void display1(tree *node)
{
    if(node->left==NULL)
    {
        cout<<node->data<<"\t";
 
        if(node->right!=NULL)
            display1(node->right);
    }
    
    else
    {
        display1(node->left);
        cout<<node->data<<"\t";
        
        if(node->right!=NULL)
            display1(node->right);
    }
}


void inorder(tree* node)
{
    if(node==NULL)
        return;
    else
    {
        inorder(node->left);
        cout<<node->data;
        inorder(node->right);
    }
}


void display2(tree *node)
{
    cout<<node->data<<"\t";
    
    if(node->left!=NULL)
    {
        display2(node->left);
        
        if(node->right!=NULL)
            display2(node->right);
    }
    else if(node->right!=NULL)
            display2(node->right);
}


void display3(tree *node)
{
    if(node->left!=NULL)
        display3(node->left);
    
    if(node->right!=NULL)
        display3(node->right);

        cout<<node->data<<"\t";
}


int main()
{
    int x;
    char ch;
    
    while(1)
    {
        cout<<"\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cin>>ch;
        switch(ch)
        {
            case '1':
                cout<<"Enter value to be inserted\n";
                cin>>x;
                node=insert(node, x);
                break;
                
            case '2':
                cout<<"Enter value to be deleted\n";
                cin>>x;
                node=remove(node, x);
                break;
                
            case '3':cout<<"1. Inorder\n2. Preorder\n3. Postorder\n";
                cin>>ch;
                switch(ch)
                {
                    case '1':
                        cout<<"INORDER DISPLAY\n\n";
                        display1(node);
                        break;
                        
                    case '2':
                        cout<<"PREORDER DISPLAY\n\n";
                        display2(node);
                        break;
                        
                    case '3':
                        cout<<"POSTORDER DISPLAY\n\n";
                        display3(node);
                        break;
                }
                
            case '4':
                exit(1);
        }
    }
}


