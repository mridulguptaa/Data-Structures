#include<bits/stdc++.h>
using namespace std;

int dpladder(int*dp,int steps,int k)
{
    dp[0]=1;
    for(int i=1;i<=steps;i++)
        for(int j=i-1;j>=0&&i-j<=k;j--)
            dp[i]+=dp[j];

    return dp[steps];


}


int main()
{
    int steps,k;        //k=max step of
    cin>>steps>>k;
    int dp[steps+1]={};
    cout<<dpladder(dp,steps,k);
    return 0;

}
