#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node*next;
}*head1=NULL,*tail1=NULL,*tail2=NULL,*head2=NULL,*ptr=NULL,*ptr2=NULL,*temp=NULL,*mergehead=NULL;

void mergekaro()
{
    ptr=head1;
    ptr2=head2;
    if(ptr->info <ptr2->info)
        {mergehead=temp=ptr;
         ptr=ptr->next;
        }
    else {mergehead=temp=ptr2;
          ptr2=ptr2->next;
         }
    /*if(head2->info < head1->info)
        temp=head2;
    else temp=head1;*/
    while(ptr!=NULL && ptr2!=NULL)
    {
        if(ptr->info <ptr2->info)
          {
            temp->next=ptr;
            temp=ptr;
            ptr=ptr->next;

          }

        else
        {
            temp->next=ptr2;
            temp=ptr2;
            ptr2=ptr2->next;

        }
    }
    if(ptr2==NULL)
        temp->next=ptr;
    if(ptr==NULL)
        temp->next=ptr2;

}
void push_1()
{
    ptr=new node;
    cin>>ptr->info;
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

void push_2()
{
    ptr=new node;
    cin>>ptr->info;
    ptr->next=NULL;
    if(head2==NULL)
    {
        head2=tail2=ptr;
    }
    else
    {
        tail2->next=ptr;
        tail2=ptr;
    }
}

void print()
{
    ptr=mergehead;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cin>>n1;
        for(int i=0;i<n1;i++)
        {
            push_1();
        }
        cin>>n2;
        for(int i=0;i<n2;i++)
        {
            push_2();
        }

        mergekaro();
        print();

        cout<<endl;
    }
    return 0;
}
