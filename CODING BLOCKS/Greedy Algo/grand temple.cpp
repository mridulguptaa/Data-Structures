#include<bits/stdc++.h>
using namespace std;

bool compare1(pair<long long int,long long int>p1,pair<long long int,long long int>p2)
{
    return p1.first<p2.first;
}

bool compare2(pair<long long int,long long int>p1,pair<long long int,long long int>p2)
{
    return p1.second<p2.second;
}

int main()
{
    long long int n,deltaXmax=-9223372036854775807,deltaYmax=-9223372036854775807;
    cin>>n;
    vector<pair<long long int,long long int>>v;
    for(long long int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare1);
    for(long long int i=1;i<n;i++)
    {
        deltaXmax=max(deltaXmax,(v[i].first-v[i-1].first)-1);
    }
    sort(v.begin(),v.end(),compare2);
    for(long long int i=1;i<n;i++)
    {
        deltaYmax=max(deltaYmax,(v[i].second-v[i-1].second)-1);
    }

    cout<<deltaXmax*deltaYmax;
    return 0;
}



