#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,ar[n-1],ar2[n-1];
    unordered_map<int,int>m;
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
         {
             int a,b;
             cin>>a>>b;
             m[a]++;
             m[b]++;
         }

    while(q--)
    {
        int root,ans=n-1;
        cin>>root;
        cout<<ans-m[root]<<" ";
    }
    return 0;
}
