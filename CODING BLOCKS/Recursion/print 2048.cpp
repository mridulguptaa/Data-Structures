#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    srand(time(NULL));
    for(int i=n-1;i>0;i--)
    {
        int j=rand()%i;
        swap(ar[j],ar[i]);
    }
    for(int i=0;i<n;i++)
        cout<<ar[i];

}
