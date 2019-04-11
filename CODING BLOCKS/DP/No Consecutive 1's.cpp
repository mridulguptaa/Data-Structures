#include<bits/stdc++.h>
using namespace std;

int countt(int n,int dp[])
{

    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-2]+dp[i-1];
    }

    return dp[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int dp[n+1]={0};
        cout<<countt(n,dp)<<endl;
    }
}
