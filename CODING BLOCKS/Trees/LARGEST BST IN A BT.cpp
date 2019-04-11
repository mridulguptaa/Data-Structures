#include<bits/stdc++.h>
using namespace std;

int maximum(int ar[],int n)
{
    vector<int>v;
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        if(v.empty()||ar[i]>v.back())
            v.push_back(ar[i]);
        else
        {
            v.clear();
            v.push_back(ar[i]);
        }
        int temp=v.size();
        maxx=max(maxx,temp);
    }
    return maxx;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];

    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<maximum(ar,n)<<endl;
    return 0;
}
