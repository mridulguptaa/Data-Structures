#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
    ~node()
    {
		if(next!=NULL){
			delete next;
		}
		cout<<"Deleting node "<<data<<endl;
	}
};

void mergekaro(node*&head,node*left,node*right);
void print(node*head);
node* mergesort(node*head);
node* middle(node*head);
void push(node *&head,node*&tail);



 node* middle(node*head)
{
    node*slow=head;
    node*fast=head->next;
    //cout<<slow->data;
    //cout<<fast->data<<endl;
    while(slow!=NULL &&fast!=NULL &&fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	//Rec Case
	node*c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;

}

node* mergesort(node*head)
{
    if(head==NULL||head->next==NULL)    //base case
        return head;
    node*mid=middle(head);
    node*left=head;
    node*right=mid->next;
    mid->next=NULL;
    mergesort(left);        //recursive
    mergesort(right);
    merge(left,right);
    return head;
}

void print(node*head)
{
    node*ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

void mergekaro(node*&head,node*left,node*right)
{
    node*ptr;
    if(left->data>right->data)
        {head=right;
         right=right->next;
        }
    else {head=left;
          left=left->next;
         }
    ptr=head;
    while(left!=NULL && right!=NULL)
    {
        if(left->data>right->data)
        {ptr->next=right;
         ptr=right;
         right=right->next;
        }
    else {ptr->next=left;
          ptr=left;
          left=left->next;
         }
    }
    if(left!=NULL)
        ptr->next=left;
    if(right!=NULL)
        ptr->next=right;
    print(head);
    cout<<endl;
}

void push(node *&head,node*&tail)
{
    int a;
    cin>>a;
    node *ptr=new node(a);
    ptr->next=NULL;
    if(head==NULL)
        head=tail=ptr;
    else
    {
        tail->next=ptr;
        tail=ptr;
    }
    //cout<<ptr->data<<head->data<<" ";
}
int main()
{
    node*head=NULL,*tail=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
     push(head,tail);
    }

    print(head);
    cout<<endl;
    node*mid=middle(head);
    cout<<mid->data<<endl;
    mergesort(head);
    print(head);


    return 0;
}
