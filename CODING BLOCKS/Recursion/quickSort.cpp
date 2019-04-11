#include<bits/stdc++.h>
using namespace std;


void swapp(int&a,int&b)
{
    int temp=a;
    a=b;
    b=temp;
}

void quicksort(int ar[],int start,int endd)
{
    if(start>=endd)
        return;
    int pivot=endd;
    int x=start-1;

    for(int j=start;j<pivot;j++)
    {
        if(ar[pivot]>=ar[j])
        {
            x++;
            swapp(ar[j],ar[x]);
        }
    }

    swapp(ar[pivot],ar[x+1]);
    quicksort(ar,start,x);
    quicksort(ar,x+2,endd);

}



int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    quicksort(ar,0,n-1);
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";

    return 0;
}
