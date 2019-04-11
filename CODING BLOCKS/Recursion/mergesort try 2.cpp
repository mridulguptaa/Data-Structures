#include<bits/stdc++.h>
using namespace std;

void mergee(int ar[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s,j=mid+1;
    int temp[100];
    for(int k=s;k<=e;k++)
    {
        if(ar[i]<ar[j])
            temp[k]=ar[i++];
        else temp[k]=ar[j++];
    }
   for(int k=0;k<s+e+1;k++)
    ar[k]=temp[k];
}

void mergesort(int ar[],int s,int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergesort(ar,s,mid);
    mergesort(ar,mid+1,e);
    mergee(ar,s,e);

}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];


    mergesort(ar,0,n);

    for(int p=0;p<n;p++)
        cout<<ar[p]<<" ";
    return 0;

}
