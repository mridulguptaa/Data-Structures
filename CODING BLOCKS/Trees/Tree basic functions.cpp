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

node*buildtree()
{
    node*ptr=new node();
    cin>>ptr->data;
    if(ptr->data!=-1)
    {
        ptr->left=buildtree();
        ptr->right=buildtree();
        return ptr;
    }
    return NULL;

}
void printtree(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    printtree(root->left);
    printtree(root->right);

}
int heightBatao(node*root)
{
    if(root==NULL)
        return 0;
    int h1=heightBatao(root->left);
    int h2=heightBatao(root->right);
    return max(h1,h2)+1;
}
void printKthlevel(int k,node*root)
{
    if(k<=0||root==NULL)
        return;
    if(k==1)
        cout<<root->data<<" ";
    else
    {
        printKthlevel(k-1,root->left);
        printKthlevel(k-1,root->right);
    }

}
void printlevelorderiterative(node*root)
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
node*buildlevelorder()
{
    node*root2=new node;
    cin>>root2->data;
    if(root2->data==-1)
        return NULL;
    queue<node*>q2;
    q2.push(root2);

    while(!q2.empty())
    {
        node*n=q2.front();
        q2.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
          {
            node*ptr=new node;
            n->left=ptr;
            ptr->data=c1;
            q2.push(ptr);
          }
        if(c2!=-1)
          {
            node*ptr=new node;
            n->right=ptr;
            ptr->data=c2;
            q2.push(ptr);
          }
    }
    return root2;
}
int main()      //1 2 3 -1 -1-1 2 3 -1 -1 3 4 -1 -1 -1
{
    node*root=buildtree();
    printtree(root);
    int height=heightBatao(root);
    cout<<endl<<"height is "<<height<<endl;
    cout<<"enter level jo print karna ho ";
    int k;
    cin>>k;
    printKthlevel(k,root);
    cout<<endl<<"printing levelWise"<<endl;
    for(int i=1;i<=height;i++)
       {
        printKthlevel(i,root);
        cout<<endl;
       }
    cout<<endl<<endl<<"level order building and printing"<<endl;
    node*root2;
    cout<<"aaye";
    root2=buildlevelorder();
    printlevelorderiterative(root2);
    return 0;
}
