#include<bits/stdc++.h>
using namespace std;

class graph
{
    long long int V;
    list<pair<long long int,long long int>>*adjList;
public:
    map<long long int,long long int>cnt;

    //constructor
    graph(long long int v)
    {
        V=v;
        adjList=new list<pair<long long int,long long int>>[V+1];
    }
    //function to add
    void addEdge(long long int u,long long int v,long long int dist)
    {
        adjList[u].push_back(make_pair(v,dist));
        adjList[v].push_back(make_pair(u,dist));
        cnt[u]=0;
        cnt[v]=0;
    }
    long long int dfs(long long int parent,map<long long int,bool>&vis)
    {
        vis[parent]=true;
        for(auto child:adjList[parent])
        {
            if(!vis[child.first])
            {
                long long int ans1=dfs(child.first,vis)+1;
                //if(ans1<cnt[parent])
                    cnt[parent]+=ans1;
            }
        }

        if(cnt[parent]==INT_MAX)
            cnt[parent]=0;
        return cnt[parent];

    }
    void HOLI(long long int parent,long long int&ans,map<long long int,bool>&vis2)
    {
        vis2[parent]=true;

        for(auto child:adjList[parent])
        {
            if(!vis2[child.first])
            {
                //cout<<child.second<<" ";
                long long int a=min(cnt[child.first]+1,V-cnt[child.first]-1);
                long long int b=cnt[parent];
                //long long int b=min(cnt[parent],V-cnt[parent]);

                ans+=2*child.second*min(a,b);
                //cout<<ans<<endl;
                HOLI(child.first,ans,vis2);

            }
        }

    }
};

int main()
{
    long long int t,tc=0;
    cin>>t;

    while(t--)
    {
        tc++;
        long long int n;
        cin>>n;
        graph g(n);
        for(long long int i=1;i<n;i++)
        {
            long long int u,v,dist;
            cin>>u>>v>>dist;
            g.addEdge(u-1,v-1,dist);
        }
        map<long long int,bool>vis;
        //g.printAdjList();
        g.dfs(0,vis);

        /*map<long long int,long long int>::iterator it=g.cnt.begin();
        map<long long int,long long int>::iterator itend=g.cnt.end();
        for(;it!=itend;++it)
           cout<<it->first<<" "<<it->second<<endl;*/
        map<long long int,bool>vis2;
        long long int ans=0;
        g.HOLI(0,ans,vis2);
        cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	return 0;
}
