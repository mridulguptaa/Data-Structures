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
        //adjList[v].push_back(make_pair(u,dist));
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

    pair<int,int> ATTACK(int parent,map<int,bool>&vis,map<int,int>&last_dist,int&cnt,int money)
    {
        vis[parent]=true;

        for(auto child:adjList[parent])
        {
            if(!vis[child.first]) //agar visited nahi hai to visit karo and call
            {
                last_dist[child.first]=child.second;
                ATTACK(child.first,vis,last_dist,cnt,money);

            }
            else    //if visited, then check last_dist and replace if required.
            {
                if(last_dist[child.first]<=child.second && money>sum+last_dist[child.first])
                {
                    sum+=last_dist[child.first];
                    last_dist[child.first]=child.second;
                    cnt++;
                }
            }
        }
        return make_pair(cnt,sum);
    }
};

int main()
{
    long long int t=1;

    while(t--)
    {
        long long int n,m,money;
        cin>>n>>m>>money;
        graph g(n);
        for(long long int i=0;i<m;i++)
        {
            long long int u,v,dist;
            cin>>u>>v>>dist;
            g.addEdge(u-1,v-1,dist);
        }
        //cin>>startpos;
        //g.printAdjList();
        map<int,bool>vis;
        map<int,int>last_dist;
        pair<int,int>ans;       //pehle mei count, second mei sum
        last_dist[0]=0;
        int sum=0,cnt=0,startpos=0;
        ans=g.ATTACK(startpos,vis,last_dist,sum,cnt,money);
        cout<<ans.first<<" "<<ans.second;

        cout<<endl;
	}
	return 0;
}
