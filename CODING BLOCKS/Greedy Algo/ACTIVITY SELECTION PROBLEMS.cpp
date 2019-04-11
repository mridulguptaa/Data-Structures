#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(make_pair(a,0));
        }
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v[i].second=a;
        }
        sort(v.begin(),v.end());
        queue<int>q;
        int endtime=INT_MIN;
        for(int i=0;i<n;i++)
        {
            //cout<<v[i].first<<" "<<v[i].second<<endl;
            if(v[i].first>=endtime)
            {
                q.push(i);
                endtime=v[i].second;
            }
        }
        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}
