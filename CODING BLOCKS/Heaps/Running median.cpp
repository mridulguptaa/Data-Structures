#include<bits/stdc++.h>
using namespace std;
int median(priority_queue<int>&q1,priority_queue<int,vector<int>,greater<int>>&q2,int num,int&c1,int&c2)
{
    if(c1==c2)
    {
        if(num>q2.top())
        {
            int temp=q2.top();
            q2.pop();
            q1.push(temp);
            q2.push(num);
        }
        else q1.push(num);
        c1++;
    }
    else if(c1>c2)
    {
        if(num<q1.top())
        {
            int temp=q1.top();
            q1.pop();
            q2.push(temp);
            q1.push(num);
        }
        else q2.push(num);
        c2++;
    }
    else if(c2>c1)
    {
        if(num>q2.top())
        {
            int temp=q2.top();
            q2.pop();
            q1.push(temp);
            q2.push(num);
        }
        else q1.push(num);
        c1++;
    }

    if(c1>c2)
        return q1.top();
    if(c2>c1)
        return q2.top();
    else return (q1.top()+q2.top())/2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c1=0,c2=0;
        cin>>n;
        priority_queue<int>q1;  //max heap
        priority_queue<int,vector<int>,greater<int>>q2; //min heap
        while(n--)
        {
            int num;
            cin>>num;
            cout<<median(q1,q2,num,c1,c2)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
