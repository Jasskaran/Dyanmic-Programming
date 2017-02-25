#include <iostream>
#include <limits.h>
using namespace std;

int max(int i,int j)
{
	return (i>j)?i:j;
}

int RodCut(int *price,int N)
{
	int table[N+1];
	table[0]=0;
	for(int i=1;i<=N;i++)
	{
		int t= INT_MIN;
		for(int j=0;j<i;j++)
		{
			t=max(t,price[i-j-1]+table[j]);
		}
		table[i]=t;
	}
	return table[N];
}

int main()
{
	int N;
	cin>>N;
	int price[N+1];
	for(int i=0;i<N;i++)
		cin>>price[i];
	cout<<RodCut(price,N);

}
