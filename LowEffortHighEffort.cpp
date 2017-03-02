#include <iostream>
#include <algorithm>
using namespace std;

int HighLowEffort(int *LE,int *HE,int N)
{
	int table[N+2];
	table[0]=0;
	table[1]=0;
	for (int i = 2; i<=N+1; ++i)
	{
		table[i]=max((table[i-1]+LE[i-2]),(table[i-2]+HE[i-2]));
	}
	// for (int i = 0; i <=N+1; ++i)
	// {
	// 	cout<<table[i]<<" ";
	// }
	return table[N+1];
}

int main()
{
	int N;
	cin>>N;
	int LE[N],HE[N];
	for (int i = 0; i < N; ++ i)
		cin>>LE[i]>>HE[i];
	cout<<HighLowEffort(LE,HE,N);
}