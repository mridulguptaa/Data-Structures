#include<bits/stdc++.h>
using namespace std;;


int main()
{
    long long int sum=0,i,j=0,n,k=0;
    map<long long int,bool>m;
    cin>>n;
    long long int ar[n+1],temp[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
        //cout<<ar[i];
        if(m[ar[i]]==false)
        {
            m[ar[i]]=true;
        }
        else
        {
            temp[j++]=ar[i];    //temp walo ko baad mei denge place
        }
    }
    sort(temp,temp+j);
    for(i=1,k=0;i<=n &&k<j;i++)
    {
        if(!m[i])
        {
            sum+=abs(temp[k]-i);
            k++;
        }
    }
    cout<<sum;

    return 0;
}
