#include<bits/stdc++.h>
using namespace std;

class graph
{
    long long int V;
    list<pair<long long int,long long int>>*adjList;
public:
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
    }

    void printAdjList()
    {
     for(long long int i=0;i<V;i++)
     {
     	cout<<i<<"->";
     	for(auto node:adjList[i])
            cout<<node.first<<","<<node.second<<"   ";
        cout<<endl;
     }
    }
    void dijkstras(long long int startpos,long long int n)
    {
        map<long long int,long long int>dist;
        set<pair<long long int,long long int>>s;      //pehle dist so that sorted based on dist
        dist[startpos]=0;
        for(long long int i=0;i<n;i++)
            if(i!=startpos)
                dist[i]=INT_MAX;
        s.insert(make_pair(0,startpos));

        while(!s.empty())
        {
            auto temp=*(s.begin());
            s.erase(s.begin());
            for(auto child:adjList[temp.second])
            {
                if(temp.first+child.second<dist[child.first])
                {
                    auto f=s.find(make_pair(dist[child.first],child.second));
                    if(f!=s.end())
                        s.erase(f);
                    dist[child.first]=temp.first+child.second;
                    s.insert(make_pair(dist[child.first],child.first));
                }
            }
        }
        for(auto d:dist)
            if(d.first!=startpos)
             {
                if(d.second==INT_MAX)
                    cout<<"-1 ";
                else cout<<d.second<<" ";
             }
           // cout<<d.first<<"ka dist hai "<<d.second<<endl;


    }

};

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,m;
        cin>>n>>m;
        graph g(n);
        for(long long int i=0;i<m;i++)
        {
            long long int u,v,dist;
            cin>>u>>v>>dist;
            g.addEdge(u-1,v-1,dist);
        }
        long long int startpos;
        cin>>startpos;
        //g.printAdjList();

        g.dijkstras(startpos-1,n);
        cout<<endl;
	}
	return 0;
}
