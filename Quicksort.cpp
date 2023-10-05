#include<iostream>
using namespace std;
static int swapcount=0,c=0,part=0;
int Partition(int A[],int p,int r)
{
	int x=A[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++)
	{	
		if(A[j]<=x)
		{
			i++;
			swap(A[i],A[j]);
			swapcount++;
		}
	}
	swap(A[i+1],A[r]);
	cout<<"\nArray status after pass "<<++c<<":\n";
	for(int i=0;i<=r;i++)
	{
		cout<<A[i]<<"\t";
	}
	return i+1;
}

void QuickSort(int A[],int p,int r)
{
	if(p<r)
	{
		int q=Partition(A,p,r);part++;
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}

int main()
{
	int A[15],n;
	cout<<"Enter no. of elements :";
	cin>>n;
	cout<<"Enter the elements one by one:";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	QuickSort(A,0,n-1);
	cout<<"\n\nFinal array after sorting:\n";
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<"\t";
	}
	cout<<"\nNo. of swaps :"<<swapcount<<endl;
	cout<<"No. of partitions :"<<part<<endl;
}

		
