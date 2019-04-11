#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node*next;
};
void push(node*&head,node*&tail)
{
    node*ptr=new node;
    cin>>ptr->info;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=tail=ptr;
    }
    else
    {
        tail->next=ptr;
        tail=ptr;
    }
}
void print(node*head)
{
    node*ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }
}
node*reversekaro(node*head)
{
    if(head==NULL ||head->next==NULL)
        return head;
    node*chead;

    chead=reversekaro(head->next);
    head->next->next=head;
    head->next=NULL;
    return chead;

}
int main()
{
    node*head=NULL,*tail=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        push(head,tail);
    print(head);
    cout<<endl;
    head=reversekaro(head);
    print(head);

}
