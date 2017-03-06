/*
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;
int max(int i,int j)
{
    return (i>j)?i:j;    
}

int MinSum(int *arr,int N,int sum)
{
    int table[sum+1];
    table[0]=0;
    map<int,int> m;
    for(int i=0;i<N;i++)
        m[arr[i]]=1;
    for(int i=0;i<=sum;i++)
    {
        if(m[i]==1)
        {
            table[i]=i;
            //break;
        }
        else {int t=0;
        for(int j=1;j<i;j++)
        {
            //if((i-j)>=0)
                t=max(t,table[j]+table[i-j]);
        }
        table[i]=t;
             }}
    //for(int i=0;i<=sum;i++)
      //  cout<<table[i]<<" ";
    return table[sum];
}
int main() {
    int T;
    cin>>T;
    while(T)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int c=MinSum(arr,n,k);
        cout<<c<<endl;
        T--;
    }

} 

