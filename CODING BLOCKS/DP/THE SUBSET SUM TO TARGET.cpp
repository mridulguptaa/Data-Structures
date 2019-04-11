#include<bits/stdc++.h>
using namespace std;

int checkkaro(int ar[],int n,int sum,int DP[],int tsum,int x)
{

    if(tsum==sum)   //base case
    {
        cout<<"Yes";
        exit(0);        //we need to print Yes once
    }
    if(tsum>sum)
        return 0;
    if(x>=n)
        return 0;

    if(DP[sum-tsum]==0)     //has been calculate. Wont lead to an answer.
        return 0;
    else
    {
        DP[sum-tsum]=max(checkkaro(ar,n,sum,DP,tsum+ar[x],x+1),checkkaro(ar,n,sum,DP,tsum,x+1));
    }

    return 0;
}

int main()
{
    int n;
    cin>>n;
    int sum,ar[n];
    cin>>sum;
    int DP[sum+1];
    for(int i=0;i<=sum;i++)
        DP[i]=-1;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    checkkaro(ar,n,sum,DP,0,0);
    cout<<"No";
    return 0;
}
