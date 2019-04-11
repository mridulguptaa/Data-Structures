#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node*right;
    node*left;
    node()
    {left=NULL;
    right=NULL;}
};

void printtreepre(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printtreepre(root->left);
    printtreepre(root->right);

}
void printtreein(node*root)
{
    if(root==NULL)
        return;
    printtreein(root->left);
        cout<<root->data<<" ";

    printtreein(root->right);

}
node*build_tree(int pre[],int in[],int n,int s,int e,int&x)
{
    //cout<<x<<endl;
    if(x>=n or s>e)
        return NULL;

    int j,rootd=pre[x++];
    node*ptr=new node();
    ptr->data=rootd;
    if(s==e)
        return ptr;
    int index;
    for(int j=s;j<=e;j++)
        if(in[j]==rootd)
        {
            index=j;
            break;
        }

    ptr->left=build_tree(pre,in,n,s,index-1,x);
    ptr->right=build_tree(pre,in,n,index+1,e,x);
    return ptr;

}
void printunder(node*root,int k)
{
    //cout<<"K is "<<k<<"and root data is"<<root->data<<endl;
    //cout<<"root ke childs are "<<root->left->data<<" "<<root->right->data<<endl;
    if(k<0 or root==NULL)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printunder(root->left,k-1);
    printunder(root->right,k-1);

}

 int print_at_dist_k(node*root,int targetd,int k)
 {
     if(root==NULL)
        return -1;
     if(root->data=targetd)
        {printunder(root,k);
         return 0;
        }
     int dl=print_at_dist_k(root->left,targetd,k);
     if(dl!=-1)
     {
         if(dl+1==k)
            cout<<root->data<<" ";
        else
        {
            cout<<"going to printunder with k= "<<k-dl-2<<endl;
            printunder(root->right,k-dl-2);
        }
        return 1+dl;
     }
    int dr=print_at_dist_k(root->right,targetd,k);
    if(dr!=-1)
    {
        if(dr+1==k)
            cout<<root->data<<" ";
        else
        {
            cout<<"going to printunder with k= "<<k-dl-2<<endl;
            printunder(root->left,k-dr-2);
        }
        return dr+1;
    }

 }
int main()
{
    int n,x=0;
    cin>>n;
    int pre[n],in[n];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    for(int i=0;i<n;i++)
        cin>>in[i];
    node*root=new node();
    root=build_tree(pre,in,n,0,n-1,x);
    //printtreepre(root);
    //printtreein(root);
    int t;
    cin>>t;
    while(t--)
    {
        int targetd,k;
        cin>>targetd>>k;
        print_at_dist_k(root,targetd,k);
        cout<<endl;
    }

    return 0;
}
