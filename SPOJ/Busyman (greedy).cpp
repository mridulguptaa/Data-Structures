#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0,temp=INT_MIN;
        cin>>n;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            int start,end;
            cin>>start>>end;
            v.push_back(make_pair(start,end));
        }
        sort(v.begin(),v.end(),compare);
        for(int i=0;i<n;i++)
        {
            if(v[i].first>=temp)
            {
                ans++;
                temp=v[i].second;

            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
