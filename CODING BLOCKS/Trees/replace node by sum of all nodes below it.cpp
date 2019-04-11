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
int karoreplace(node*root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL &&root->right==NULL)
        return root->data;

    int temp=root->data;
    int sumleft=karoreplace(root->left);
    int sumright=karoreplace(root->right);
    root->data=sumleft+sumright;
    return temp+sumleft+sumright;


}

int main()      //1 2 3 -1 -1-1 2 3 -1 -1 3 4 -1 -1 -1
{
    node*root=buildtree();
    //printtree(root);
    karoreplace(root);
    printtree(root);
    return 0;
}
