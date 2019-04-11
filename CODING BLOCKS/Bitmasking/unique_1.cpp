#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    for(i=1;i<n;i++)
        ar[0]=ar[0]^ar[i];
    cout<<ar[0];


	return 0;
}
