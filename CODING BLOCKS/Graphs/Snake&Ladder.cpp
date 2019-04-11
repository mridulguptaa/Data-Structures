#include<bits/stdc++.h>
using namespace std;


//Adj List Implementation for Integer Nodes

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
    void addEdge(int u,int v,int dist=1)
    {
        adjList[u].push_back(make_pair(v,dist));
        adjList[v].push_back(make_pair(u,dist));
    }

    int GAME(map<int,int>ladder,map<int,int>snake)
    {
        map<int,bool>visited;
        queue<int>q;
        map<int,int>dist;
        dist[1]=0;
        q.push(1);
        visited[1]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(int i=1;i<=6;i++)
            {

                if(!visited[temp+i])
                {
                    q.push(temp+i);
                    addEdge(temp,temp+i);
                    if(ladder[temp+i]!=0)
                    {addEdge(temp,ladder[temp+i]);
                     dist[ladder[temp+i]]=dist[temp]+1;
                     visited[ladder[temp+i]]=true;
                    }
                    if(snake[temp+i]!=0)
                    {addEdge(temp,snake[temp+i]);
                     //dist[ladder[temp+i]]=dist[temp]+1;
                     visited[ladder[temp+i]]=true;
                    }
                    visited[temp+i]=true;
                    dist[temp+i]=dist[temp]+1;
                }
            }
        }
        return dist[100];
    }

};

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int Nladders,Nsnakes,minsteps;
        cin>>Nladders>>Nsnakes;
        map<int,int>ladder; //contain upper point of ladder
        map<int,int>snake;  //contain lower point of snake
        graph g(101);
        for(int i=0;i<Nladders;i++)
        {
            int start,end;
            cin>>start>>end;
            ladder[start]=end;
        }
        for(int i=0;i<Nsnakes;i++)
        {
            int start,end;
            cin>>start>>end;
            snake[start]=end;
        }
        //g.printAdjList();
        minsteps=g.GAME(ladder,snake);
        cout<<minsteps;
        cout<<endl;
	}

    return 0;
}
