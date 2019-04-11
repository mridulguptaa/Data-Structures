#include<bits/stdc++.h>
using namespace std;
map<int,int>hashy;

int karomaxfind(int ar[],int n,int DP[],int maxx)
{
    DP[0]=0;
    DP[1]=hashy[1];

    for(int i=2;i<=maxx;i++)
    {
        int ans1=hashy[i]*2+DP[i-2];
        int ans2=DP[i-1];
        DP[i]=max(ans1,ans2);
    }

    return DP[maxx];

}

int main()
{
    int n;
    cin>>n;
    int ar[n],maxx;

    for(int i=0;i<n;i++)
        {
         cin>>ar[i];
         hashy[ar[i]]++;
         maxx=max(maxx,ar[i]);
        }
    int DP[maxx+1];
    cout<<karomaxfind(ar,n,DP,maxx);

    return 0;
}
