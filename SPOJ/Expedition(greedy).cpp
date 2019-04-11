#include<bits/stdc++.h>
using namespace std;

bool compare(pair<long long int,long long int>p1,pair<long long int,long long int>p2)
{
    if(p1.first==p2.first)
        return p1.second>p2.second;
    return p1.first<p2.first;
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,count=0,tdist,fuel,travelled=0,flag=0,laststop=0,tempmaxpos=0,tempmaxfuel=0;
        cin>>n;
        vector<pair<long long int,long long int>>v;
        for(long long int i=0;i<n;i++)
        {
            long long int dist,fuel;
            cin>>dist>>fuel;
            v.push_back(make_pair(dist,fuel));
        }
        cin>>tdist>>fuel;
        v.push_back(make_pair(0,fuel));
        v.push_back(make_pair(9223372036854775807 ,0));      //next fueltank at infinity dist

        for(long long int i=1;i<=n;i++)
            v[i].first=tdist-v[i].first;    //taking dist of fuel tank from  starting polong long int.

        sort(v.begin(),v.end(),compare);
        while(travelled+fuel<tdist)
        {
            for(int i=laststop+1;v[i].first-v[laststop].first<=fuel && i<=n;i++)
            {
                if(v[i].second>tempmaxfuel)
                {
                    tempmaxfuel=v[i].second;
                    tempmaxpos=i;
                }
            }
            count++;
            travelled=v[tempmaxpos].first;
            fuel=fuel-(v[tempmaxpos].first-v[laststop].first)+v[tempmaxpos].second;
            laststop=tempmaxpos;

        }
       if(travelled+fuel<tdist)
        cout<<"-1"<<endl;
       else cout<<count<<endl;
    }

    return 0;

}
