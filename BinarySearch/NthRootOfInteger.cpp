#include <bits/stdc++.h>
using namespace std;

long long NthRoot(int N,int M)
{
    int st = 1,end = M;
    while(st<=end)
    {
        long long mid = st+(end-st)/2;
        if((long long)pow(mid,N) > (long long)M)
        {
            end = mid-1;
        }
        else if((long long)pow(mid,N) < (long long)M)
        {
            st = mid+1;
        }
        else 
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int N = 3,M = 100;

    cout<<NthRoot(N,M)<<endl;

    return 0;
}