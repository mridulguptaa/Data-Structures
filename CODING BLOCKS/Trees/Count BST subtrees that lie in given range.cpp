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
/*void printpreorder(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}*/
bool countkaro(node*root,int&count,int low,int high)
{
    if(root==NULL)
    {
        return true;
    }
    if(countkaro(root->left,count,low,high) &&countkaro(root->right,count,low,high))
        //if(root->data<=high &&root->data>=low)
        {
            count++;
            return true;
        }
    return false;

}
int main()
{
    int n,count=0;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int low,high;
    cin>>low>>high;
    node*root;
    root=arraytobst(ar,0,n-1);
    countkaro(root,count,low,high);
    cout<<count<<endl;
    return 0;
}
