#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<pair<int,int>>*adjList;
public:
    //constructor
    graph(int v)
    {
        V=v;
        adjList=new list<pair<int,int>>[V+1];
    }
    //function to add
    void addEdge(int u,int v,int dist)
    {
        adjList[u].push_back(make_pair(v,dist));
        adjList[v].push_back(make_pair(u,dist));
    }

    void printAdjList()
    {
     for(int i=0;i<V;i++)
     {
     	cout<<i<<"->";
     	for(auto node:adjList[i])
            cout<<node.first<<","<<node.second<<"   ";
        cout<<endl;
     }
    }
    void bfs(int source,int n)
    {
        map<int,bool>visited;
        queue<int>q;
        map<int,int>dist;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto it:adjList[temp])
            {
                if(!visited[it.first])
                {
                    q.push(it.first);
                    visited[it.first]=true;
                    dist[it.first]=dist[temp]+6;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            if(j!=source)
            {
                if(dist[j]==0)
                    cout<<"-1 ";
                else cout<<dist[j]<<" ";
            }
        }
    }

};

int main()
{
    int t;
    cin>>t;
    int defaultsize=6;
    while(t--)
    {
        int n;
        cin>>n;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            int u,v,dist;
            cin>>u>>v>>dist;
            g.addEdge(u-1,v-1,dist);
        }
        int ans=0;
        //g.printAdjList();
        g.bfs(0,ans);
        cout<<ans<<endl;
	}
	return 0;
}
