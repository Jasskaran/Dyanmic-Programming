#include <iostream>
#include <algorithm>
using namespace std;


class job
{
	public:
	int startTime;
	int finishTime;
	int profit;
	job() {}
	
};


bool jobcomparator(job s1, job s2)
{
	return (s1.finishTime < s2.finishTime);
}

int WJS(job *s, int N)
{
	sort(s,s+N,jobcomparator);
	int table[N];
	for(int i=0;i<N;i++)
	{
		table[i]=s[i].profit;
	}
	for (int i = 1; i < N; ++i)
	{
		for (int j=(i-1);j>=0;j--)
		{
			//int st=s[i].startTime, ft=s[j].finishTime;
			if(s[i].startTime >= s[j].finishTime)
			{
				table[i]=table[i]+s[j].profit;
				break;
			}
		}
	}

	return max(table[N-1],table[N-2]);
}

int main()
{
	int N;
	cin>>N;
	job s[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>s[i].startTime>>s[i].finishTime>>s[i].profit;
	}
	cout<<WJS(s,N);
}
