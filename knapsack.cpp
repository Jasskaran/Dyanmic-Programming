#include <iostream>

using namespace std;

int max(int i,int j)
{
	return (i>j)?i:j;
}
int Knapsack(int *wt,int *value,int W,int N)
{
	int k[W+1][N+1];
	for(int i=0;i<=W;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(i==0 || j==0)
				k[i][j]=0;
			else if(wt[j-1]<=i)
				k[i][j]=max(k[i][j-1],value[j-1]+k[i-wt[j-1]][j-1]);
			else
				k[i][j]=k[i][j-1];
		}

	}
	// for(int i=0;i<=W;i++)
	// {
	// 	for(int j=0;j<=N;j++)
	// 	{
	// 		cout<<k[i][j]<<" ";
	// 	}
	// }
	return k[W][N];
}

int main()
{
	int N;
	cin>>N;
	int wt[N],value[N];
	for(int i=0;i<N;i++)
	{
		cin>>wt[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin>>value[i];
	}
	//cout<<"enter knapsack wt";
	int W;
	cin>>W;
	cout<<Knapsack(wt,value,W,N);
}
