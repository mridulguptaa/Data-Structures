
/*
node*buildtree()
{
    while(n--)
    {
        node*ptr=new node();
        int d;
        cin>>d;
        ptr->left=buildtree();
        ptr->data=
        ptr->right=buildtree();

    }
    return ptr

node*insertt(int a,node*root)
{
    node*ptr=new node;
    if(root==NULL)
    {
    ptr->data=a;
    root=ptr;
    return root;
    }
    else
    {
        if(a<=root->data)
            {ptr=insertt(a,root->left);
            root->left=ptr;
            }
        else
        {
            ptr=insertt(a,root->right);
            root->right=ptr;
        }

    }

    return root;
}

node*buildbst(int n)
{
    node*root;
    while(n--)
    {
        int a;
        cin>>a;
        root=insertt(a,root);
    }
    return root;
}
*/
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node*right;
    node*left;
    node(int d)
    {left=NULL;
    right=NULL;
    data=d;
    }
};

node*arraytobst(int ar[],int s,int e)
{
    if(s>e)
        return NULL;
    int mid=(s+e)/2;
    node*root=new node(ar[mid]);
    root->left=arraytobst(ar,s,mid-1);
    root->right=arraytobst(ar,mid+1,e);
    return root;
}
void printpreorder(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
int replacesum(node*root,int&sum)
{
    if(root==NULL)
        return 0;
    replacesum(root->right,sum);
    sum+=root->data;
    root->data=sum;
    replacesum(root->left,sum);
    return root->data;
}
int main()
{
    int n,sum=0;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    node*root;
    root=arraytobst(ar,0,n-1);
    replacesum(root,sum);
    printpreorder(root);
    return 0;
}
