#include<bits/stdc++.h>
using namespace std;


queue<int> reversekaro(queue<int>&q,int n)
{
    if(q.size()==1)
        return q;
    int temp=q.front();
    q.pop();
    reversekaro(q,n);
    q.push(temp);
    return q;
}

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main()
{
    int n;
    int temp,i;
    cin>>n;
    queue<int>q;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        q.push(temp);
    }
    reversekaro(q,n);
    print(q);
    cout<<"END";
    return 0;
}
