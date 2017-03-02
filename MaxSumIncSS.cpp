/*For example,

if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)

if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10)

if the input array is {10, 5, 4, 3}, then output should be 10*/

#include <iostream>
#include <limits.h>
using namespace std;

int MaxSumIncSS(int *arr,int N)
{
	int table[N+1];
	table[0]=0;
	table[1]=arr[0];
	int maxi=INT_MIN;
	for(int i=2;i<=N;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(arr[i-1]>arr[j-1])
			{
				table[i]=table[j]+arr[i-1];
				maxi=max(maxi,table[i]);
			}
		}
	}
	// for(int i=0;i<=N;i++)
	// 	cout<<table[i]<<" ";
	return (maxi>table[1]?maxi:table[1]);
}

int main()
{
	int N;
	cin>>N;
	int arr[N];
	for (int i = 0; i < N; ++i)
		cin>>arr[i];
	int c=MaxSumIncSS(arr,N);
	cout<<c;
}
