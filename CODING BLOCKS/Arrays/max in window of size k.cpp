#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n;
    cin>>n;
    char ar[n];
    int value[256];
    for(i=0;i<256;i++)
        value[i]=-1;
    for(i=0;i<n;i++)
        cin>>ar[i];

    int curlen=0,maxlen=0,last_index;


    for(i=0;i<n;i++)
    {
        last_index=value[ar[i]];
        if(value[ar[i]]==-1 || i-curlen>last_index)
        {
            curlen++;
            maxlen=max(curlen,maxlen);
        }
         maxlen=max(curlen,maxlen);
         value[ar[i]]=i;
    }


    cout<<maxlen<<endl;
    return 0;
}
