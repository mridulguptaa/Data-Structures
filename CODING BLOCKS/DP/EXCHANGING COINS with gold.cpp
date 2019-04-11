#include<bits/stdc++.h> //USE HASH MAP, DONT DO FOR NUMBERS TILL N.
using namespace std;

int GoldMax(int n,int dp[])
{
    for(int i=1;i<=n;i++)
    {
        int ans1=dp[i/2]+dp[i/3]+dp[i/4];
        dp[i]=max(i,ans1);
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    dp[0]=0;
    cout<<GoldMax(n,dp);
    return 0;
}
