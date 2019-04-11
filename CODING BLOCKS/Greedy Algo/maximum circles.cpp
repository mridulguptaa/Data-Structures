#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long int,long long int>p1,pair<long long int,long long int>p2)
{
    return (p1.first+p1.second)<(p2.first+p2.second);
}

int main()
{
    long long int n,countt=0;
    long long int end=-9223372036854775807,start=-9223372036854775807;
    cin>>n;
    vector<pair<long long int,long long int>>v;
    for(long long int i=0;i<n;i++)
    {
        long long int c,r;
        cin>>c>>r;
        v.push_back(make_pair(c,r));
    }
    sort(v.begin(),v.end(),compare);
    /*for(int i=0;i<n;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
        */
    for(long long int i=0;i<n;i++)
    {
        if(v[i].first-v[i].second<end &&v[i].first-v[i].second>start)
            countt++;
        else
        {   end=v[i].first+v[i].second;
            start=v[i].first-v[i].second;
        }
    }
    cout<<countt;
    return 0;
}
