#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n;
    cin>>w;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int i=0;
    int j=w-1;
    int sum=0;
    int max_sum=0;
    for(int t=0; t<w; t++)
    {
        sum+=arr[t];
        max_sum+=arr[t];
    }
    while(j<n-1)
    {
        sum+=arr[j+1];
        sum-=arr[i];
        if(sum>max_sum)
        {
            max_sum=sum;
        }
        i++;
        j++;
    }
    cout<<max_sum;
}