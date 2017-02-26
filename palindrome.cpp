#include <iostream>
#include <string>

using namespace std;

int palindrome(string str)
{
	int l=str.size();
	cout<<l;
	int table[l+1][l+1];
	for(int i=0;i<=l;i++)
	{
		for(int j=0;j<=l;j++)
		{
			if(i==0|| j==0) 
				table[i][j]=0;
			else if(str[i-1]==str[l-j])
				table[i][j]=table[i-1][j-1]+1;
			else
				table[i][j]=max(table[i][j-1],table[i-1][j]);
		}
	}
	// for(int i=0;i<=l;i++)
	// {
	// 	for(int j=0;j<=l;j++)
	// 		cout<<table[i][j]<<" ";
	// 	cout<<endl;
	// }
	return table[l][l];
}

int main()
{
	string str;
	cin>>str;
	int c=palindrome(str);
	cout<<c;
}