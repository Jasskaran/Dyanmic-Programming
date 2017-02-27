#include <iostream>
#include <string>
using namespace std;

int LCS(string str1,string str2)
{
	int l1=str1.size();
	int l2=str2.size();
	int table[l2+1][l1+1];
	cout<<l1<<endl;
	cout<<l2<<endl;
	for(int i=0;i<=l2;i++)#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int LCS(string str1,string str2)
{
	int l1=str1.size();
	int l2=str2.size();
	int table[l2+1][l1+1];
	cout<<l1<<endl;
	cout<<l2<<endl;
	int maxi=INT_MIN;
	for(int i=0;i<=l2;i++)
	{
		for(int j=0;j<=l1;j++)
		{
			if(i==0|| j==0)
				table[i][j]=0;
			else if(str1[j-1]==str2[i-1])
			{
				table[i][j]=table[i-1][j-1]+1;
				maxi=max(maxi,table[i][j]);
			}
			else
				table[i][j]=table[i-1][j];
		}
	}
	// for(int i=0;i<=l2;i++)
	// {
	// 	for(int j=0;j<=l1;j++)
	// 		cout<<table[i][j]<<" ";
	// 	cout<<endl;
	// }
	return maxi;
   
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	int c=LCS(str1,str2);
	cout<<c;
}
	{
		for(int j=0;j<=l1;j++)
		{
			if(i==0|| j==0)
				table[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				table[i][j]=table[i-1][j-1]+1;
			else
				table[i][j]=table[i-1][j];
		}
	}
	for(int i=0;i<=l2;i++)
	{
		for(int j=0;j<=l1;j++)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}
	return 0;
   
}

int main()
{
	string str1,str2;
	cin>>str1>>str2;
	int c=LCS(str1,str2);
	cout<<c;
}
