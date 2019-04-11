#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,m,f;
    cin>>n>>m>>f;
    long long int ar1[n],ar2[m];
    for(long long int i=0;i<n;i++)
        cin>>ar1[i];
    for(long long int i=0;i<m;i++)
        cin>>ar2[i];
    sort(ar1,ar1+n);
    sort(ar2,ar2+m);
    long long int ans=INT_MIN;
    for(long long int i=0;i<n;i++)
    {
        long long int a=abs(ar1[i]-ar2[i]);
        long long int b=abs(ar2[i]-f);
        ans=max(ans,a+b);
    }
    cout<<ans;

    return 0;
}
