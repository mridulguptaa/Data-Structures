#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
    node*prev;
};
void build(node*&head,node*&tail)
{
    node*ptr=new node;
    cin>>ptr->data;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=tail=ptr;
        head->prev=NULL;
    }
    else
    {
        tail->next=ptr;
        ptr->prev=tail;
        tail=ptr;
    }
}
node*reversekaro(node*head,int k)
{
    node*curr=head,*next=NULL,*prev=NULL;
    int count=0;
    while(count<k&&curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
        head->next=reversekaro(next,k);
    return prev;
}
void print(node*head)
{
    node*ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main()
{
    int n,k;
    cin>>n;
    node*head=NULL,*tail=NULL;
    for(int i=0;i<n;i++)
        build(head,tail);

    cin>>k;
    head=reversekaro(head,k);
    print(head);
    return 0;
}
