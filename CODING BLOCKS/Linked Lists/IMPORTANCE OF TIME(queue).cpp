#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,time=0;
    cin>>n;
    int ar[n];
    queue<int>q;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }
    for(i=0;i<n;i++)
        cin>>ar[i];
    i=0;
    while(!q.empty())
    {
        if(q.front()==ar[i])
        {
            q.pop();
            time++;
            i++;
        }
        else
        {
            int temp=q.front();
            q.pop();
            q.push(temp);
            time++;
        }
    }
    cout<<time;
    return 0;
}
