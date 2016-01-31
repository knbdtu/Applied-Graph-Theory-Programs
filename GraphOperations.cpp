#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool comp(const pair<pair<int,int>,char> &A,const pair<pair<int,int>,char> &B)
{
	if(A.first.first==B.first.first)
	{
		if(A.first.second==B.first.second)
		{
			return A.second<B.second;
		}
		else
		{
			return A.first.second<B.first.second;
		}
	}
	else
	{
		return A.first.first<B.first.first;
	}
}

int main()
{
    cout<<"For graph G1 :-\n";
    int N_G1,M_G1,N_G2,M_G2;
	vector<int>::iterator it;
	vector<pair<pair<int,int>,char> >::iterator ite;

    cout<<"Enter  the number of vertices :-";
    cin>>N_G1;

    vector<int> vertices_G1;

    cout<<"Enter the vertices :-";
    for(int i=0;i<N_G1;i++)
	{
		int U;
		cin>>U;
		vertices_G1.push_back(U);
	}
	sort(vertices_G1.begin(),vertices_G1.end());

	cout<<"Enter the number of edges :-";
	cin>>M_G1;

	vector<pair<pair<int,int>,char> > edges_G1;
	cout<<"Enter the edges :-\n";
	for(int i=0;i<M_G1;i++)
	{
		int U,V;
		char ch;
		cin>>U>>V>>ch;
		edges_G1.push_back(make_pair(make_pair(U,V),ch));
	}
	sort(edges_G1.begin(),edges_G1.end(),&comp);

	cout<<"For graph G2 :- \n";

    cout<<"Enter  the number of vertices :-";
    cin>>N_G2;

    vector<int> vertices_G2;

    cout<<"Enter the vertices :-";
    for(int i=0;i<N_G2;i++)
	{
		int U;
		cin>>U;
		vertices_G2.push_back(U);
	}
	sort(vertices_G2.begin(),vertices_G2.end());

	cout<<"Enter the number of edges :-";
	cin>>M_G2;

	vector<pair<pair<int,int>,char> > edges_G2;
	cout<<"Enter the edges :-\n";
	for(int i=0;i<M_G2;i++)
	{
		int U,V;
		char ch;
		cin>>U>>V>>ch;
		edges_G2.push_back(make_pair(make_pair(U,V),ch));
	}
	sort(edges_G2.begin(),edges_G2.end(),&comp);

	//For Union
	vector<int>vertices_union(vertices_G1.size()+vertices_G2.size());

    it=set_union(vertices_G1.begin(),vertices_G1.end(),vertices_G2.begin(),vertices_G2.end(),vertices_union.begin());
	vertices_union.resize(it-vertices_union.begin());

	vector<pair<pair<int,int>,char> >edges_union(edges_G1.size()+edges_G2.size());

	ite=set_union(edges_G1.begin(),edges_G1.end(),edges_G2.begin(),edges_G2.end(),edges_union.begin());
	edges_union.resize(ite-edges_union.begin());

    cout<<"The vertices of graph after union operation are:-";
    for(int i=0;i<vertices_union.size();i++)
	{
		cout<<vertices_union[i]<<" ";
	}
	cout<<endl;

	cout<<"The edges of graph after union operation are:-\n";
    for(int i=0;i<edges_union.size();i++)
	{
		cout<<edges_union[i].first.first<<" "<<edges_union[i].first.second<<" "<<edges_union[i].second<<endl;
	}
	cout<<endl;

	//For Intersection
	vector<int>vertices_intersection(vertices_G1.size()+vertices_G2.size());

    it=set_intersection(vertices_G1.begin(),vertices_G1.end(),vertices_G2.begin(),vertices_G2.end(),vertices_intersection.begin());
	vertices_intersection.resize(it-vertices_intersection.begin());


	vector<pair<pair<int,int>,char> >edges_intersection(edges_G1.size()+edges_G2.size());

	ite=set_intersection(edges_G1.begin(),edges_G1.end(),edges_G2.begin(),edges_G2.end(),edges_intersection.begin());
	edges_intersection.resize(ite-edges_intersection.begin());

    cout<<"The vertices of graph after intersection operation are:-";
    for(int i=0;i<vertices_intersection.size();i++)
	{
		cout<<vertices_intersection[i]<<" ";
	}
	cout<<endl;

	cout<<"The edges of graph after intersection operation are:-\n";
    for(int i=0;i<edges_intersection.size();i++)
	{
		cout<<edges_intersection[i].first.first<<" "<<edges_intersection[i].first.second<<" "<<edges_intersection[i].second<<endl;
	}
	cout<<endl;

	//Ring Sum
	vector<int>vertices_ringsum(vertices_union.begin(),vertices_union.end());
	vector<pair<pair<int,int>,char> >edges_ringsum(edges_union.size()+edges_intersection.size());
	ite=set_difference(edges_union.begin(),edges_union.end(),edges_intersection.begin(),edges_intersection.end(),edges_ringsum.begin());
	edges_ringsum.resize(ite-edges_ringsum.begin());

	cout<<"The vertices of graph after ring sum operation are:-";
    for(int i=0;i<vertices_ringsum.size();i++)
	{
		cout<<vertices_ringsum[i]<<" ";
	}
	cout<<endl;

	cout<<"The edges of graph after ring sum operation are :-\n";
    for(int i=0;i<edges_ringsum.size();i++)
	{
		cout<<edges_ringsum[i].first.first<<" "<<edges_ringsum[i].first.second<<" "<<edges_ringsum[i].second<<endl;
	}
	cout<<endl;
	return 0;
}
