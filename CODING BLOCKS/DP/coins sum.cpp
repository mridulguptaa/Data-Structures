#include<bits/stdc++.h>
using namespace std;

int countkaro(int total,int ar[],int n,int dp[])
{
    cout<<dp[total]<<" ";
    if(total<=0)
        return 1;

    if(dp[total]==0)
    {
        for(int i=0;i<n;i++)
        {
            if(dp[total-ar[i]]==0)
                dp[total-ar[i]]=countkaro(total-ar[i],ar,n,dp);

            dp[total]+=dp[total-ar[i]];
            /*if(dp[total-ar[i]]==-1)
                dp[total-ar[i]]=countkaro(total-ar[i],ar,n,dp);
            else
                dp[total-ar[i]]+=countkaro(total-ar[i],ar,n,dp);

            temp+=dp[total-ar[i]]+1;*/
        }
        //dp[total]=temp;

    }
    return dp[total];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        int total;
        cin>>total;
        int dp[total+1];
        memset(dp,0,sizeof(dp));
        int ans;
        ans=countkaro(total,ar,n,dp);
    }

    return 0;
}
