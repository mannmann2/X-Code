

#include <iostream>
#include <string.h>
#define MAX 50

using namespace std;
int main()
{
    char a[MAX], a1[MAX];
    
    cin>>a;
 
    int l=strlen(a);
    //cout<<l;
    
    int k=0;
    for(int i=0; i<l; i++)
    {
        for(int j=l-1; j>=i; j--)
        {
    
            if(a[j]==a[i])
            {
                a1[k]=a[i];
                a[i]=0;
                k++;
                a1[k]=a[j];
                a[j]=0;
                k++;
                
                break;
                
            }
            
        }
    }

label:
    
    for(int i=0; i<l;i++)
    {
           if(i%2==0)
            cout<<a1[i];
    }
    
     cout<<" ";
    
    for(int i=l-1; i>=1;i--)
    {
        if(i%2!=0)
            cout<<a1[i];
    }
    
    return 0;
}

