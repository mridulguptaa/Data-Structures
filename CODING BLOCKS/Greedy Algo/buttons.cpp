#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,p,ans=0;
    cin>>n>>p;
    long long int ar[n];
    for(long long int i=0;i<n;i++)
        cin>>ar[i];
    map<long long int,bool>m;
    for(long long int i=0;i<n;i++)
    {
        long long int temp=ar[i];
        long long int but=temp/p;
        if(temp%p!=0)
            but++;
        if(!m[but])
        {
            m[but]=true;
            //cout<<"adding "<<but<<endl;
            ans+=but;
        }
        else
        {
            while(true)
            {
                if(!m[++but])
                {
                    m[but]=true;
                    //cout<<"adding "<<but<<endl;
                    ans+=but;
                    break;
                }
            }
        }
    }
    cout<<ans;

    return 0;

}
