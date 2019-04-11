#include<bits/stdc++.h>
using namespace std;

int main()
{
    uint64_t n,i,j,count=0;
    cin>>n;

    for(i=0;i<=n;i++)
        for(j=0;j<=n-i;j++)
            if(i&j&(n-i-j))
                count++;
    count%=1000000007;
    cout<<count;


    return 0;
}
