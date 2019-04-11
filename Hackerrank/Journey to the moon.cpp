#include<iostream>
#include<list>
using namespace std;

class Graph{
public:

	long long int V;
	list<long long int> *l;


	Graph(long long int V){
		this->V = V;
		l = new list<long long int>[V];
	}

	void addEdge(long long int u,long long int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}
	long long int dfsVisit(long long int s,bool *visited){
		visited[s] = true;
		long long int cnt = 1;

		for(auto child:l[s]){
			if(!visited[child]){
				cnt += dfsVisit(child,visited);
			}
		}
		return cnt;
	}

	long long int dfs(){
		bool *visited = new bool[V+1]{0};


		long long int ans = V*(V-1)/2;
		for(long long int i=0;i<V;i++){
			if(!visited[i]){
				long long int cnt = dfsVisit(i,visited);
				ans -= (cnt)*(cnt-1)/2;
			}
		}
        cout<<ans;
	}


};

int main(){

	long long int n,m;
	cin>>n>>m;
	Graph g(n);
	while(m--)
    {
        long long int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }

	g.dfs();


}
