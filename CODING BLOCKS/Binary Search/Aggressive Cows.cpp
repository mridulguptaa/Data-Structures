#include<bits/stdc++.h>
using namespace std;

int AGGCOWS(int ar[],int n,int cows)
{
    int static s=0,e=ar[n-1],mid,first_false,last_true,tempcows=cows,k;

    do
    {
        mid=(s+e)/2;        //mid will be our gap
        tempcows--;
        k=ar[0];
        for(int i=1;i<n &&tempcows>0;i++)
        {
            if(ar[i]-mid>=k)
            {
                tempcows--;
                k=ar[i];
            }

        }
        if(tempcows==0)
            {
                last_true=mid;
                s=mid+1;
            }
        else
            {
               first_false=mid;
               e=mid-1;
            }
        tempcows=cows;
    }while(s<=e);

    return last_true;
}


int main()
{
    int n,cows;
    cin>>n>>cows;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);

    cout<<AGGCOWS(ar,n,cows);

    return 0;
}
