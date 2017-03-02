/*3 2 5 10 7 ...returns 15
 3 2 7 10*/

#include <iostream>
using namespace std;

int SumWithoutAdj(int *arr,int N)
{
	int sum0=arr[0],sum1=arr[1];
	for(int i=2;i<N;i++)
	{
		if((i%2)==0)
			sum0=sum0+arr[i];
		else
			sum1=sum1+arr[i];
	}
	return (sum0>sum1)?sum0:sum1;
}

int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	int c=SumWithoutAdj(arr,N);
	cout<<c;
}
