#include<iostream>
#include<vector>
using namespace std;

vector<int> G[12345];

bool dfs(int U,vector<int> &assigned_jobs,vector<bool> &visited)
{
	for(int i=0;i<G[U].size();i++)
	{
		if(!visited[G[U][i]])
		{
			visited[G[U][i]]=true;
			if(assigned_jobs[G[U][i]]<0||dfs(assigned_jobs[G[U][i]],assigned_jobs,visited))
			{
				assigned_jobs[G[U][i]]=U;
				return true;
			}
		}
	}
	return false;
}
int maximum_bipartite_matching(int N)
{
	vector<int> assigned_jobs(N+1,-1);
	int matchings=0;
	for(int i=1;i<=N;i++)
	{
		vector<bool> visited(N+1,false);
		if(dfs(i,assigned_jobs,visited))
		{
			++matchings;
		}
	}
	return matchings;
}

int main()
{
	int N;
    cout<<"Enter the number of vertices :-";
    cin>>N;

    int M;
    cout<<"Enter the number of edges :-";
    cin>>M;

    cout<<"Enter directed edges :-\n";
    for(int i=0;i<M;i++)
    {
        int U,V;
        cin>>U>>V;
        G[U].push_back(V);
    }
    cout<<"Maximum matching in a bipartite graph is :-"<<maximum_bipartite_matching(N)<<endl;
    return 0;
}
