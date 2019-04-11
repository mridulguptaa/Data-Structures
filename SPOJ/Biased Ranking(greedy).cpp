#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,long long int>p1,pair<string,long long int>p2)
{
    return p1.second<p2.second;
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,badness=0;
        cin>>n;
        vector<pair<string,long long int>>v;
        for(long long int i=0;i<n;i++)
        {
            string s;
            long long int r;
            cin>>s>>r;
            v.push_back(make_pair(s,r));
        }
        sort(v.begin(),v.end(),compare);
        for(long long int i=1;i<=n;i++)
        {

            if(v[i-1].second>i)
                badness+=v[i-1].second-i;
            else badness+=i-v[i-1].second;

        }
        cout<<badness<<endl;
    }
    return 0;
}
