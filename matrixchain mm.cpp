#include<iostream>
#define max 50
using namespace std;
int num,pLen;
int m[max][max],s[max][max];

void printOptimalParens(int s[][max],int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		printOptimalParens(s,i,s[i][j]);
		printOptimalParens(s,s[i][j]+1,j);
		cout<<")";
	}
}
 
void MatrixChainOrder(int p[])
{
	int n=pLen-1;
	int q,j;
	for(int i=1;i<=n;i++)
		m[i][i]=0;

	for(int l=2;l<=n;l++)
	{	
		for(int i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=999999;
			for(int k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	cout<<"M matrix :\n";
	for(int i=1;i<=num;i++)
	{
		for(int j=i;j<=num;j++)
		{
			cout<<m[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"S matrix :\n";
	for(int i=1;i<=num-1;i++)
	{
		for(int j=i+1;j<=num;j++)
		{
			cout<<s[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Optimal Parenthesization :";	
	printOptimalParens(s,1,num);
}


int main()
{
	cout<<"Enter no. of matrices :";cin>>num;
	int p[num+2];
	for(int i=1;i<=num;i++)
	{
		cout<<"Enter the dimensions of A"<<i<<" matrix : ";
		cin>>p[i-1]>>p[i];
	}
	pLen=num+1;
	MatrixChainOrder(p);
}
	
	
	
	

