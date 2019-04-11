#include<bits/stdc++.h>
using namespace std;

int setbits(uint64_t n)
{
    int count=0,j=0;
    while(n!=0)
    {
        if((n&1)!=0)
            count++;
        n=n>>1;

    }
    return count;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        uint64_t n,ans=0;
        cin>>n;
        ans=setbits(n);
        cout<<ans<<endl;
    }
    return 0;
}
