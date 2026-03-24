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
    vector<int> nums = {1, 2, 4, 8, 16};
    int cows = 3;
    int n = nums.size();

    sort(nums.begin(),nums.end());

    int maxm = nums[n-1];
    int minm = nums[0];
    int ans = 0;

    for(int i=1;i<=maxm-minm;i++)
    {
        if(canPlace(nums,cows,i))
        {
            ans  = i;
        }
    }

    cout<<ans<<endl;


    return 0;
}