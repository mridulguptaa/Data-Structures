#include<bits/stdc++.h>
using namespace std;

int main()
{
    int j,i,first,second,third,n,sum;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    cin>>sum;
    unordered_map<int,int>m;
    for(i=0;i<n;i++)
        m[ar[i]]++;     //mapping done
    for(i=0;i<n;i++)
    {
        first=ar[i];
        for(j=0;j<n;j++)
        {
            second=ar[j];
            third=m[sum-first-second];
            if(third!=0)
                cout<<first<<" "<<second<<" "<<third<<endl;
        }

    }

    return 0;
}
