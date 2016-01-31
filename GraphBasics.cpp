#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    cout<<"Enter the number of vertices :-";
    cin>>N;

    vector<int> degree(N+1,0);
    int M;

    cout<<"Enter the number of edges :-";
    cin>>M;

    cout<<"Enter two vertices for which an edge exists between them :-\n";
    for(int i=0;i<M;i++)
    {
        int U,V;
        cin>>U>>V;
        ++degree[U];
        ++degree[V];
    }

    cout<<"The vertices with even number of degree is :-";
    for(int i=1;i<=N;i++)
    {
        if(degree[i]%2==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;

    cout<<"The vertices with odd number of degree is :-";
    for(int i=1;i<=N;i++)
    {
        if(degree[i]%2==1)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
	return 0;
}
