#include<iostream>
using namespace std;

unsigned long long int fac(int a)
{
    unsigned long long int b=1;
    for(int i=1;i<=a;i++)
        b=((i%107)*(b%107))%107;
    return b;
}

int main()
{
    int n;
    unsigned long long int ans=0;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(i=0;i<n;i++)
    {
        ans=(fac(ar[i])%107+ans%107)%107;
    }
    cout<<ans;


	return 0;
}
