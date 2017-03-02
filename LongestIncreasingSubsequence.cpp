#include <iostream>
#include <limits.h>
using namespace std;

int LargestIncreasingSubsequence(int *arr,int length)
{
	int table[length+1];
	table[0]=0;
	int maxi=INT_MIN;
	for(int i=1;i<=length;i++)
	{
		table[i]=1;
		for(int j=1;j<i;j++)
		{
			if(arr[i-1]>arr[j-1] && (table[j]>=table[i]))
			{
				table[i]=table[j]+1;
				maxi=max(maxi,table[i]);
			}
		}
	}
	// for (int i = 0; i<=length; ++i)
	// 	cout<<table[i]<<" ";
	return maxi;
} 

int main()
{
	int length;
	cin>>length;
	int arr[length];
	for(int i=0;i<length;i++)
		cin>>arr[i];
	int c=LargestIncreasingSubsequence(arr,length);
	cout<<c;
}