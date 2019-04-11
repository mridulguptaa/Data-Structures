#include<bits/stdc++.h>
using namespace std;

int fun(int a,int b)
{
    if(b==0)
        return a;

    return fun(b,a%b);
}


int main()
{
    int ans,a,b;
    cin>>a>>b;
    ans=fun(a,b );
    cout<<ans;

}
