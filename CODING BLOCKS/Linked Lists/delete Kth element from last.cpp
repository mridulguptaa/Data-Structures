#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node*next;
}*ptr=NULL,*head1=NULL,*tail1=NULL,*ptr2=NULL;

void push(int n)
{
    ptr=new node;
    ptr->info=n;
    ptr->next=NULL;
    if(head1==NULL)
    {
        head1=tail1=ptr;
    }
    else
    {
        tail1->next=ptr;
        tail1=ptr;
    }
}

void findKth(int k)
{
    ptr=ptr2=head1;
    for(int i=1;i<k;i++)
        ptr=ptr->next;
    while(ptr!=NULL)
    {
        if(ptr->next==NULL)
            cout<<ptr2->info;
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
}
int main()
{
    int n=0;
    do
    {
        cin>>n;
        if(n!=-1)
            push(n);
    }while(n!=-1);
    int k;
    cin>>k;
    findKth(k);
    return 0;
}
