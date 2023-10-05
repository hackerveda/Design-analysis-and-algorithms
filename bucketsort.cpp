#include<iostream>
using namespace std;

int main()
{
  double d[]={0.76,0.72,0.82,0.39,0.37,0.43};
  double a[10][10],key;
  int c,h,i,k;
  double temp[10],g[10];

  for(int i=0;i<=9;i++)
  {
    a[i][0]=0;
  }
  for(int i=0;i<6;i++)
  {
    int x=d[i]*10;
    a[x][0]+=1;
    c=a[x][0];
    a[x][c]=d[i];
  }

  cout<<endl; 
  cout<<"\n"<<"Bucket elements are:\n";
        for(int i=0;i<=9;i++)
      {

     if(a[i][0]==0)
     continue;
    else
    {
       c=a[i][0];
      for(k=1;k<=c;k++)
          cout<<"\t"<<a[i][k];
    }
    cout<<endl;
    

  
  }
  cout<<"sorted array is: "<<endl;
  for(int j=0;j<=9;j++)
  {
    if (a[j][0]!=0)
    {

        if(a[j][0]==1)
         {cout<<"\t"<<a[j][1];}

      else
      {  
        c=a[j][0];
           for(k=1;k<=c;k++)
              g[k]=a[j][k];
        
   
        for(int h=2;h<=c;h++)
        {
          key=g[h];
          i=h-1;
          while(i>0 && g[i]>key)
          {
            
            g[i+1]=g[i];
            i=i-1;
          }
          g[i+1]=key;
      
        }

        for(int k=1;k<=c;k++)
        cout<<g[k]<<"\t";
      }
    }
  }
  return 0;
}