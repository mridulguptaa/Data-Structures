#include<bits/stdc++.h>
using namespace std;

long long int kthnikalo(priority_queue<long long int,vector<long long int>,greater<long long int>>&q,long long int k,long long int n)
{
    vector<long long int>v;
    long long int i=1;
    while(i<k)
    {
        long long int temp=q.top();
        q.pop();
        v.push_back(temp);
        i++;
    }
    long long int ans=q.top();
    q.pop();
    while(v.size())
    {
        q.push(v.front());
        v.erase(v.begin());
    }
    return ans;
}
int main()
{
    long long int n,j,i;
    cin>>n;
    long long int ar[n]={0};
    for(long long int p=0;p<3;p++)
    for(i=0;i<n;i++)
    {
       cin>>j;
       ar[i]+=j;
    }

    priority_queue<long long int,vector<long long int>,greater<long long int>>q;
    for(i=0;i<n;i++)
        q.push(ar[i]);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int k;
        cin>>k;
        if(k>q.size())
            cout<<"-1"<<endl;
        else
            cout<<kthnikalo(q,k,n)<<endl;
    }
    return 0;
}
