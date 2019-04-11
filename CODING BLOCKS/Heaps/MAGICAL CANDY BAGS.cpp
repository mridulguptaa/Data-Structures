#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k;
        priority_queue<long long int>Q;
        while(n--)
        {
            long long int a;
            cin>>a;
            Q.push(a);
        }
        long long int sum=0;
        while(k--)
        {
            long long int temp=Q.top();
            sum+=temp;
            Q.pop();
            temp/=2;
            Q.push(temp);
        }
        cout<<sum<<endl;
    }
    return 0;
}
