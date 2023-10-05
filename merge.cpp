//merge sort
#include<iostream>
using namespace std;

void Merge(int A[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	cout<<"\np="<<p<<"\t"<<"q="<<q<<endl;
	int L[n1],R[n2];
	cout<<"\nn1="<<n1<<"\t"<<"n2="<<n2<<endl;

	//left array
	for(int i=0;i<n1;i++)
	{
		L[i]=A[p+i];
	}
	L[n1]=9999;
	cout<<"\nLeft array:\n";
	for(int a=0;a<n1;a++)
	{
		cout<<L[a]<<"\t";
	}

	//right array
	for(int j=0;j<n2;j++)
	{
		R[j]=A[q+j+1];
	}
	R[n2]=9999;
	cout<<"\nRight array:\n";
	for(int a=0;a<n2;a++)
	{
		cout<<R[a]<<"\t";
	}

	int i=0,j=0;

	//merge of left and right arrays
	for(int k=p;k<=r;k++)
	{
		cout<<"\np="<<p<<"\t"<<"r="<<r<<endl;
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}

	cout<<"\nArray after merging:\n";
	cout<<"\nr="<<r<<endl;
	for(int a=0;a<=r;a++)
	{
		cout<<A[a]<<"\t";
	}
}
void MergeSort(int A[],int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}



int main()
{
	int A[20];
	int n;
	cout<<"Enter n ";
	cin>>n;
	cout<<"Enter elements ";
	for(int i=0;i<n;i++)
		cin>>A[i];
	MergeSort(A,0,n-1);
}

