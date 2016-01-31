#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ranks;
vector<int> parent;

void Make_Set(int &N)
{
	ranks.clear();
	parent.clear();
	ranks.resize(N,0);
	parent.resize(N,0);
	for(int i=0;i<N;i++)
	{
		parent[i]=i;
		ranks[i]=0;
	}
}

int Find_Set(int p)
{
	while(parent[p]!=p)
	{
		parent[p]=parent[parent[p]];
		p=parent[p];
	}
	return p;
}

void Union_Set(int p,int q)
{
	int x=Find_Set(p);
	int y=Find_Set(q);

	if(ranks[x]<ranks[y])
	{
		parent[x]=y;
	}
	else if(ranks[x]>ranks[y])
	{
		parent[y]=x;
	}
	else
	{
		parent[y]=x;
		ranks[x]+=1;
	}
}

struct Edge
{
	int source;
	int destination;
	int weight;
};

vector<Edge> E;
bool comp(const Edge &A,const Edge &B)
{
	return A.weight<B.weight;
}

int main()
{

	int N,M;

	cout<<"Enter the number of vertices :-";
	cin>>N;

	cout<<"Enter the number of edges :-";
    cin>>M;
	E.clear();
	E.resize(M,{0,0,0});

	Make_Set(N);

	cout<<"Enter edges along with their respective weights:-\n";
	for(int i=0;i<M;i++)
	{
		int U,V,W;
		cin>>U>>V>>W;
		E[i].source=U;
		E[i].destination=V;
		E[i].weight=W;
	}
	sort(E.begin(),E.end(),comp);

	int total_cost=0;
	vector<pair<int,int> >MST_edges;

	for(int i=0;i<M;i++)
	{
		int X=Find_Set(E[i].source);
		int Y=Find_Set(E[i].destination);
		if(X!=Y)
		{
			Union_Set(E[i].source,E[i].destination);
			MST_edges.push_back(make_pair(E[i].source,E[i].destination));
			total_cost+=E[i].weight;
		}
	}

	cout<<"The edge set of MST formed using Kruskals Algorithm is :-\n";

    for(int i=0;i<MST_edges.size();i++)
    {
        cout<<MST_edges[i].first<<" "<<MST_edges[i].second<<endl;
    }

	cout<<"Total cost of constructing MST using Kruskals Algorithm is :- "<<total_cost<<endl;
	return 0;
}
