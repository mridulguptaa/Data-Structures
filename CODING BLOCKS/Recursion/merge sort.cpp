#include<bits/stdc++.h>
using namespace std;

void mergesort(int ar[],int n)
{
    if(n<=1)
    {

             return ;
    }

    int mid=n/2;
    int ar1[mid];
    for(int i=0;i<mid;i++)
        ar1[i]=ar[i];
    mergesort(ar1,mid);

    int ar2[n-mid];
    for(int i=mid;i<n;i++)
        ar2[i-mid]=ar[i];
    mergesort(ar2,n-mid);

    //lets merge

    int i=0,j=0;

    for(int z=0;z<n;z++)
    {
        if(ar1[i]<ar2[j])
        {
            ar[z]=ar1[i];
            i++;
        }
        else
        {
            ar[z]=ar2[j];
            j++;
        }
    }

    return;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    mergesort(ar,n);

    for(int z=0;z<n;z++)
        cout<<ar[z]<<" ";
    return 0;

}
