/*10
1 2 3 4 5 6 7 8 9 10
output is 40*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int NoTwoCons(long int *arr,long int N)
{
    long int table[N+1];
    table[0]=0;
    table[1]=arr[0];
    table[2]=(arr[0]+arr[1]);
    for(long int i=3;i<=N;i++)
    {
        table[i]=max((arr[i-1]+arr[i-2]+table[i-3]),arr[i-1]+table[i-2]);
        table[i]=max(table[i],table[i-1]);
    }
    return table[N];
}

int main() {
    long int N;
    cin>>N;
    long int arr[N];
    for(long int i=0;i<N;i++)
        cin>>arr[i];
    long int c=NoTwoCons(arr,N);
    cout<<c;
    return 0;
}
