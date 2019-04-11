#include<bits/stdc++.h>
using namespace std;

class graph
{
    long long int V;
    list<long long int>*adjList;
public:
    //constructor
    graph(long long int v)
    {
        V=v;
        adjList=new list<long long int>[V+1];
    }
    //function to add
    void addEdge(long long int u,long long int v,map<long long int,pair<long long int,long long int>>&m)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        if(u>v)
        {
            m[u].first++;
            m[v].second++;
        }
        else
        {
            m[u].second++;
            m[v].first++;
        }
    }

    void printAdjList()
    {
     for(long long int i=0;i<V;i++)
     {
     	cout<<i<<"->";
     	for(auto node:adjList[i])
            cout<<node<<"  , ";
        cout<<endl;
     }
    }

};

int main()
{
        long long int vertices,edges,count=0;
        cin>>vertices>>edges;
        graph g(vertices);
        map<long long int,pair<long long int,long long int>>m;    //first mei small wale, second mei big wale
        for(long long int i=0;i<edges;i++)
        {
            long long int u,v;
            cin>>u>>v;
            g.addEdge(u-1,v-1,m); //0 se indexing lunga
        }

       // g.printAdjList();
        for(long long int i=1;i<vertices;i++)
        {
            if(m[i].first<m[i].second)
                count++;
        }
        cout<<count;

	return 0;
}
