#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<pair<int,int>>*adjList;
    bool temple;
public:
    //constructor
    graph(int v)
    {
        V=v;
        adjList=new list<pair<int,int>>[V+1];
        temple=false;
    }
    //function to add
    void addEdge(int u,int v,int dist=INT_MAX)
    {
        adjList[u].push_back(make_pair(v,dist));
        adjList[v].push_back(make_pair(u,dist));
    }


     int minmoney(int root,map<int,bool>&vis,int T,int R)
    {
        vis[root]=true;
        //case 1:build temple at this node
        int ans1=T;

        for(auto child:adjList[root])
        {
            if(!vis[child.first])
            {
                ans1+=minmoney(child,vis,T,R);
            }
        }

        int ans2=0,ans3=0;
        for(auto child:adjList[root])
        {

            if(!vis[child])
            {
                ans1+=minmoney(child,vis,T,R);
            }
        }

    }


};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,T,R;
        cin>>n>>m>>T>>R;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        int count=0;
        map<int,bool>vis;
        int ans=minmoney(0,vis,T,R);
        cout<<ans<<endl;
	}
	return 0;
}
