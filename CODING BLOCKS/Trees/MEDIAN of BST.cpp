#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);
    int median;
    if(n%2==1)
        median=ar[n/2];
    else median=(ar[n/2]+ar[n/2-1])/2;
    cout<<median;



    return 0;
}
