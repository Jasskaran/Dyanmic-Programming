#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
	int stime;
	int ftime;
	int profit;
};

job* CreateNJob(int st,int ft,int profit)
{
	job* NewJob=new job;
	NewJob->stime=st;
	NewJob->ftime=ft;
	NewJob->profit=profit;
	return NewJob;
}

bool jobcomparator(job *s1,job *s2)
{
	return (s1->ftime)<(s2->ftime);
}

int WJS(job* s[],int N)
{
	sort(s,s+N,jobcomparator);
	int table[N];
	for (int i = 0; i < N; ++i)
	{
		table[i]=s[i]->profit;
	}
	for (int i = 1; i < N; ++i)
		for(int j=(i-1);j>=0;j--)
			if((s[i]->stime)>=(s[j]->ftime))
			{
				table[i]=table[i]+s[j]->profit;
				break;
			}
		for (int i = 0; i < N; ++i)
		{
			cout<<table[i]<<" ";
		}
	return max(table[N-1],table[N-2]);
}
int main()
{
	int N;
	cin>>N;
	job* s[N];
	int st,ft,pt;
	for (int i = 0; i < N; ++i)
	{
		cin>>st>>ft>>pt;
		s[i]=CreateNJob(st,ft,pt);
	}
	cout<<WJS(s,N);
}