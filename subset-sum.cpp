#include <iostream>

using namespace std;

bool SubSet(int *set,int N,int value)
{
	bool table[value+1][N+1];
	for(int i=0;i<=value;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(i==0)
				table[i][j]=true;
			else if(i!=0 && j==0)
				table[i][j]=false;
			else if((i-set[j-1])>=0)
			{
				if(table[i-set[j-1]][j-1]==true)
					table[i][j]=true;
				else
					table[i][j]=table[i][j-1];
			}
			else
				table[i][j]=table[i][j-1];
		}
	}
	//for(int i=0;i<=value;i++)
	// {
	// 	for(int j=0;j<=N;j++)
	// 		cout<<table[i][j]<<" ";
	// 	cout<<endl;
	// }
	return table[value][N];
}

int main()
{
	int N;
	cin>>N;
	int set[N];
	for(int i=0;i<N;i++)
		cin>>set[i];
	int value;
	cin>>value;
	int c=SubSet(set,N,value);
	cout<<c;
}

