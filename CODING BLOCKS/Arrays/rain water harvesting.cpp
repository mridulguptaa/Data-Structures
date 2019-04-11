#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {

    int n,i;
    cin>>n;
    int ar[n],ar1[n],ar2[n],tmax=0,water=0;
    for(i=0;i<n;i++)
        cin>>ar[i];

    for(i=0;i<n;i++)
    {
        if(ar[i]>tmax)
            tmax=ar[i];
        ar1[i]=tmax;
    }

    tmax=0;

    for(i=n-1;i>=0;i--)
    {
        if(ar[i]>tmax)
            tmax=ar[i];
        ar2[i]=tmax;
    }

    for(i=0;i<n;i++)
    {
        water+=min(ar1[i],ar2[i])-ar[i];
    }
    cout<<water;
    }
    return 0;
}
