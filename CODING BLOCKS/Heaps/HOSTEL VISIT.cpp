#include<bits/stdc++.h>
using namespace std;

long long int Kthsmallest(priority_queue<long long int,vector<long long int>,greater<long long int>>Q,long long int k)
{
    k--;
    while(k--)
    {
        Q.pop();
    }
    return Q.top();
}

int main()
{
    long long int k,q;
    priority_queue<long long int,vector<long long int>,greater<long long int>>Q;
    cin>>q>>k;
    while(q--)
    {
        long long int t;
        cin>>t;
        if(t==1)
        {
            long long int x,y,dist;
            cin>>x>>y;
            dist=(x*x)+(y*y);
            Q.push(dist);
        }
        if(t==2)
        {
            cout<<Kthsmallest(Q,k)<<endl;
        }
    }
    return 0;
}
