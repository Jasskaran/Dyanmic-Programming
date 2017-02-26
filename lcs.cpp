#include <iostream>
#include <string>

using namespace std;

int lcs(string str1,int l1,string str2,int l2)
{
	cout<<str1<<" "<<str2;
	int table[l1+1][l2+1];
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0|| j==0) 
				table[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				table[i][j]=table[i-1][j-1]+1;
			else
				table[i][j]=max(table[i][j-1],table[i-1][j]);
		}
	}
	
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}
	return table[l1][l2];
}

int main()
{
	int l1,l2;
	cin>>l1>>l2;
	string str1,str2;
	cin>>str1>>str2;
	int c=lcs(str1,l1,str2,l2);
	cout<<c;
}