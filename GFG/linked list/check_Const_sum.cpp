#include<bits/stdc++.h>
using namespace std;

void karosum(int ar[],int temp[],int n,int sumfind,int sum,int k,int i)
{
    if(sum==sumfind)
    {   //printing final ans.
        for(int j=0;j<k;j++)        //k mein number of elements in temp.
            cout<<temp[j]<<" ";
        exit(0);
    }
    for(int z=i;(sum+ar[z])<=sumfind;z++)
     {
        temp[k]=ar[z];
        sum+=ar[z];
        karosum(ar,temp,n,sumfind,sum,k+1,i+1);
     }

    k--;        //backtracking
    sum-=temp[k];
    temp[k]=0;

}


int main()
{
    int n,sumfind;
    cin>>n;
    int ar[n],temp[n]={};
    cout<<"Enter elements in array";
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<endl<<"Enter Sum"<<endl;
    cin>>sumfind;
    sort(ar,ar+n);
    karosum(ar,temp,n,sumfind,0,0,0);
    cout<<endl<<"Sum naii bana :( ";

}
