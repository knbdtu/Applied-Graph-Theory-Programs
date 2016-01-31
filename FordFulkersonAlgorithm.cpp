#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

vector<vector<int> > residual_graph(1234,vector<int>(1234,0));
vector<vector<int> > graph(1234,vector<int>(1234,0));
vector<int> parent(1234,-1);

bool bfs(int source,int sink,int N)
{
	vector<bool> visited(N+1,false);
	queue<int> Q;

    Q.push(source);
    visited[source]=true;
    parent[source]=-1;

    while(!Q.empty())
	{
		int U=Q.front();
		Q.pop();

		for(int i=1;i<=N;i++)
		{
			if(!visited[i]&&residual_graph[U][i]>0)
			{
				Q.push(i);
				visited[i]=true;
				parent[i]=U;
			}
		}
	}
	return visited[sink]==true;
}

int FordFulkerson(int source,int sink,int N)
{
	int max_flow=0;
	while(bfs(source,sink,N))
	{
		int path_flow=INT_MAX;

		for(int v=sink;v!=source;v=parent[v])
		{
			int u=parent[v];
			path_flow=min(path_flow,residual_graph[u][v]);
		}

		for(int v=sink;v!=source;v=parent[v])
		{
			int u=parent[v];
			residual_graph[u][v]-=path_flow;
			residual_graph[v][u]+=path_flow;
		}
		max_flow+=path_flow;
	}
	return max_flow;
}
int main()
{
	int N;
    cout<<"Enter the number of vertices :-";
    cin>>N;

	int M;
    cout<<"Enter the number of edges :-";
    cin>>M;

    cout<<"Enter directed edges along with their respective weights:-\n";
    for(int i=0;i<M;i++)
    {
        int U,V,W;
        cin>>U>>V>>W;
        graph[U][V]=W;
        residual_graph[U][V]=graph[U][V];
    }

	int source;
	cout<<"Enter the source :-";
	cin>>source;

	int sink;
	cout<<"Enter the sink :-";
	cin>>sink;

	cout<<"Maximum flow in a network :-"<<FordFulkerson(source,sink,N)<<endl;
	return 0;
}
