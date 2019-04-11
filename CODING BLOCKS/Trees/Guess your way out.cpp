#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    long long int data;
    node*right;
    node*left;
    node(long long int d)
    {left=NULL;
    right=NULL;
    data=d;
    }
};
node*buildtree(long long int height,long long int n)
{
    if(height<0)
        return NULL;
    if(height>=0)
    {
        node*root=new node(0);
        root->left=buildtree(height-1,n);
        root->right=buildtree(height-1,n);
        return root;
    }
}

bool baharniklo(node*root,long long int&count,long long int n,long long int x)
{
    if(root==NULL)
          return false;
    if(root->data==1)
    {
        cout<<count<<endl;
        return true;
    }
    if(root->data!=-1)
        {
            count++;
            root->data=-1;
        }
    if(x%2==1)
        {if(!baharniklo(root->left,count,n,x+1))
            baharniklo(root->right,count,n,x);
         return false;
        }
    else
        {
            if(!baharniklo(root->right,count,n,x+1))
                baharniklo(root->left,count,n,x);
            return false;
        }

    return false;
}
void levelorderiterative(node*root)
{
    queue<node*>q;
    q.push(root);

    while(!q.empty())
    {
        node*n=q.front();
        q.pop();
        cout<<n->data<<" ";
        if(n->left!=NULL)
            q.push(n->left);
        if(n->right!=NULL)
            q.push(n->right);
    }
}
void setkaro(node*root,long long int&tempo,long long int n)
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL&&tempo==n)
    {
        root->data=1;
    }
    if(root->left==NULL&&root->right==NULL)
        tempo++;
    setkaro(root->left,tempo,n);
    setkaro(root->right,tempo,n);
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int height,n,ncpy,count=0,temp=1,tempo=1;
        cin>>height>>n;
        node*root=buildtree(height,n);
        setkaro(root,tempo,n);
        //prlong long intlevelorderiterative(root);
        //cout<<endl;
        baharniklo(root,count,n,1);
    }
    return 0;
}
