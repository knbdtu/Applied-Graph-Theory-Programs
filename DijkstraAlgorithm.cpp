#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

int main()
{
    int N;
    cout<<"Enter the number of vertices :-";
    cin>>N;

    vector<pair<int,int> > G[N+1];
    int M;

    cout<<"Enter the number of edges :-";
    cin>>M;

    cout<<"Enter directed edges along with their respective weights:-\n";

    for(int i=0;i<M;i++)
    {
        int U,V,W;
        cin>>U>>V>>W;
        G[U].push_back(make_pair(V,W));
    }

    int S;
    cout<<"Enter the source node :-";
    cin>>S;

    vector<int> parent(N+1,-1);
    vector<int> dist(N+1,123456789);

    dist[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > PQ;
    PQ.push(make_pair(dist[S],S));

    while(!PQ.empty())
    {
        pair<int,int> H=PQ.top();
        PQ.pop();

        if(H.first<=dist[H.second])
        {
            for(int i=0;i<G[H.second].size();i++)
            {
                if(dist[G[H.second][i].first]>dist[H.second]+G[H.second][i].second)
                {
                    dist[G[H.second][i].first]=dist[H.second]+G[H.second][i].second;
                    PQ.push(make_pair(dist[G[H.second][i].first],G[H.second][i].first));
                }
            }
        }
    }

    int D;
    cout<<"Enter the destination point :-";
    cin>>D;

    cout<<"The shortest path between the source and destination node is :-"<<dist[D]<<endl;
    return 0;
}
