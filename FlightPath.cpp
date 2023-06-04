#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0,0};
int visited[50] = {0};

int main()
{
	cout<<"Enter no. of cities: ";
	int n, u;
	cin>>n;
	string cities[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter city #"<<i<<" (Airport Code): ";
		cin>>cities[i];
	}
	cout<<"\nYour cities are: "<<endl;
	for(int i=0; i<n; i++)
		cout<<"city #"<<i<<": "<<cities[i]<<endl;
	cout<<"\n Enter 0 if there is no flight between cities \n ";
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			cout<<"Enter required fuel to reach "<<cities[i]<<" and "<<cities[j]<<": ";
			cin>>adj_mat[i][j];
			adj_mat[j][i] = adj_mat[i][j];
		}
	}
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<"\t"<<cities[i]<<"\t";
	for(int i=0; i<n; i++)
	{
		cout<<"\n"<<cities[i];
		for(int j=0; j<n; j++)
			cout<<"\t"<<adj_mat[i][j]<<"\t";
		cout<<endl;
	}
}
