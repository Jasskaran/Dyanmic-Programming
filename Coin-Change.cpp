#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int CoinChange(int *coins,int N,int V)
{
	int table[V+1];
	table[0]=0;
	for(int i=1;i<=V;i++)
	{
		int t=INT_MAX;
		for(int j=1;j<(N+1);j++)
		{
			if(i==coins[j-1])
				t=1;
			else if((i-coins[j-1])>0)
				t=min(t,table[i-coins[j-1]]+1);
		}
		table[i]=t;
		// cout<<i<<" "<<table[i]<<endl;
	}
	
	return table[V];
}


int main()
{
	int N;
	cin>>N;
	int coins[N];
	for(int i=0;i<N;i++)
		cin>>coins[i];
	int V;
	cin>>V;
	int c=CoinChange(coins,N,V);
	cout<<c;
}
