#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long long long int n,temp=0;
    cin>>n;
    long long long long int out[n],ar[n];
    for(long long int i=0;i<n;i++)
    {
         cin>>ar[i];
         temp=max(temp,ar[i]);
    }
    long long int subar[temp+1]={0};
    for(long long long long int i=0;i<n;i++)
        subar[ar[i]]++;
    for(long long int i=1;i<=temp;i++)
        subar[i]+=subar[i-1];

    for(long long int i=0;i<n;i++)
    {
        out[subar[ar[i]]-1]=ar[i];
        subar[ar[i]]--;
    }
    for(long long int i=0;i<n;i++)
        cout<<out[i]<<" ";


    return 0;
}
