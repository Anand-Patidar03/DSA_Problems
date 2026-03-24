#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool canPlace(vector<int> &nums,int cows,int x)
{
    int cntcows = 1, lastCows = nums[0];
    int n = nums.size();

    for(int i=1;i<n;i++)
    {
        if(nums[i]-lastCows >= x)
        {
            cntcows++;
            lastCows = nums[i];
        }
        else 
        {
            continue;
        }
    }
    if(cntcows >= cows)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


int main()
{
    vector<int> nums = {0,3,4,7,10,9};
    int cows = 4;
    int n = nums.size();

    sort(nums.begin(),nums.end());

    int maxm = nums[n-1];
    int minm = nums[0];
    int ans = 0;

    int st = 1,end = maxm-minm;
    while(st<=end)
    {
        int mid = st+(end-st)/2;
        if(canPlace(nums,cows,mid))
        {
            ans = mid;
            st = mid+1;
        }
        else 
        {
            end = mid-1;
        }
    }

    cout<<ans<<endl;


    return 0;
}