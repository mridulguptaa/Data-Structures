#include<bits/stdc++.h>
using namespace std;

int LIS(int ar[],int n)
{
    int DP[n+1],temp=0;
    DP[0]=0;

    for(int i=0;i<n;i++)
    {
        if(ar[i]>temp)
        {
            DP[i+1]=1+DP[i];
            temp=ar[i];
        }
        else
        {
            temp=ar[i];
            DP[i+1]=DP[i];
        }
    }

    return DP[n];
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<LIS(ar,n);
    return 0;
}
