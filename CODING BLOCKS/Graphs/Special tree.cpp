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
    pair<int,bool> dfs(int&sum,int root,map<int,bool>vis)
    {
        if(vis[root])       //base case
            return make_pair(0,false);
        vis[root]=true;
        for(auto child:adjList[root])
        {
            if(vis[child.first])
                return make_pair(0,false);
            else
            {
                int temp;
                if(dfs(sum,child.first,vis).second)
                {
                    temp=dfs(sum,child.first,vis).first;
                    sum+=temp;
                }
                else sum+=child.second;
            }
        }
        return make_pair(sum,true);
    }
};

int main()
{
        int n,m,dist,minsum=INT_MAX;
        cin>>n>>m;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            int u,v,dist;
            cin>>u>>v>>dist;
            g.addEdge(u-1,v-1,dist);
        }
        for(int i=0;i<n;i++)
        {
            int sum=0;
            map<int,bool>vis;
            if((g.dfs(sum,i,vis)).second)
                if(minsum>sum)
                    minsum=sum;
        }
        //g.printAdjList();
        cout<<minsum;

	return 0;
}
