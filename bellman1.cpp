#include<iostream>
#include<bits/stdc++.h>
#define inf 1000
#define max 100
using namespace std;
struct edge
{
	int u,v,wt;
}
e[max];
int d[max],w[max][max],s,nv,ne,pi[max];
int main()
{
	int f,t,weight,i,j,u,v;
	cout<<"Bellman Ford algorithm "<<endl;
	cout<<"Enter number of vertices and edges "<<endl;
	cin>>nv>>ne;
	cout<<"Enter source vertex "<<endl;
	cin>>s;
	for(i=1;i<=nv;i++)
	{
		d[i]=inf;
		pi[i]=-1;
	}
	d[s]=0;
	for(i=1;i<=ne;i++)
	{
		cout<<"Enter edge "<<i<<":"<<endl;
		cin>>f>>t;
		cout<<"Enter Weight "<<i<<":"<<endl;
		cin>>weight;
		w[f][t]=weight;
		e[i].u=f;
		e[i].v=t;
		e[i].wt=weight;
	}
	for(i=1;i<=nv;i++)
	{
		for(j=1;j<=ne;j++)
		{
			u=e[j].u;
			v=e[j].v;
			if(d[v]>d[u]+w[u][v])
			{
				d[v]=d[u]+w[u][v];
				pi[v]=u;
			}
		}
	}
	int cycle=0;
	for(j=1;j<=ne;j++)
	{
		u=e[j].u;
		v=e[j].v;
		if(d[v]>d[u]+w[u][v])
		{
			cycle=1;
			break;
		}
	}
	if(!cycle)
	{
		cout<<"shortest distance from vertex "<<s<<"to every other vertices "<<endl;
		for(i=2;i<=nv;i++)
			cout<<i<<"\t"<<d[i]<<endl;
	}
	else
	{
		cout<<"contains negative cycle "<<endl;
	}
	return 0;
}
