#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int>*adjList;
public:
    //constructor
    graph(int v)
    {
        V=v;
        adjList=new list<int>[V+1];
    }
    //function to add
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printAdjList()
    {
     for(int i=0;i<V;i++)
     {
     	cout<<i<<"->";
     	for(auto node:adjList[i])
            cout<<node<<",";
        cout<<endl;
     }
    }

    void dfs(int parent,int&count,map<int,bool>&vis)
    {
        vis[parent]=true;

        for(auto child:adjList[parent])
        {
            if(!vis[child])
            {
                count++;
                dfs(child,count,vis);

            }
        }

    }
};


int main()
{
        int n,m,minans=INT_MAX;
        cin>>n>>m;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            g.addEdge(u-1,v-1);
        }
        //g.printAdjList();
        map<int,bool>vis;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
             int count=1;
             g.dfs(i,count,vis);
             if(minans>count)
                minans=count;
            }
        }
        cout<<minans;

	return 0;
}
