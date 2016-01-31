#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
    cout<<"Enter the number of vertices :-";
    cin>>N;

    vector<vector<int> > G(N+1,vector<int>(N+1,123456789));
    int M;

    cout<<"Enter the number of edges :-";
    cin>>M;

    cout<<"Enter directed edges along with their respective weights:-\n";

    for(int i=0;i<M;i++)
    {
        int U,V,W;
        cin>>U>>V>>W;
        G[U][V]=W;
    }

	for(int i=1;i<=N;i++)
	{
		G[i][i]=0;
	}

    for(int k=1;k<=N;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}

	cout<<"Shortest Path between every pair of vertices in a graph is given by :-"<<endl;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(G[i][j]!=123456789)
			{
				cout<<G[i][j]<<" ";
			}
			else
			{
				cout<<"INF ";
			}
		}
		cout<<endl;
	}
	return 0;
}
