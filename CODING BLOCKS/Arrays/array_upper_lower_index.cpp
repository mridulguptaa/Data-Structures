#include<iostream>
using namespace std;

int main()
{
    int n,t,i;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    cin>>t;
    while(t--)
    {
        int num,low=-1,upp=-1;
        cin>>num;
        for(i=0;i<n;i++)
            if(ar[i]==num)
            {
                low=i;
                break;
            }
        for(i=n-1;i>=0;i--)
            if(ar[i]==num)
            {
                upp=i;
                break;
            }
        cout<<low<<" "<<upp<<endl;
    }


    return 0;
}
