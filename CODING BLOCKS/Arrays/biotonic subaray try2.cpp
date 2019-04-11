#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,cursum=0,maxsum=0;
        cin>>n;
        int ar[n];
        int tempar[n];
        for(i=0;i<n;i++)
            cin>>ar[i];
        for(i=1;i<n-1;i++)
        {
            if(ar[i]<ar[i-1]&&ar[i]<ar[i+1])
                tempar[i]=0;
            else tempar[i]=1;
        }

        tempar[0]=1;
        tempar[n-1]=1;

        for(i=0;i<n;i++)
        {
            cursum++;
            maxsum=max(maxsum,cursum);
            if(tempar[i]==0)
                cursum=1;
        }
        cout<<maxsum<<endl;


    }
    return 0;
}
