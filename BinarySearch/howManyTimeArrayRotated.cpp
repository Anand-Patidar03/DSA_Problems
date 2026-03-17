#include <bits/stdc++.h>
using namespace std;

int findRotations(vector<int>& nums)
{
    int n = nums.size();
    
    int st = 0;
    int end = n - 1,idx=0;
    int minm = INT_MAX;

    while(st <= end)
    {
        int mid = st + (end - st) / 2;
        if(nums[st] <= nums[mid])
        {
            if(nums[st] < minm)
            {
                minm = nums[st];
                idx = st;
            }
            st = mid+1;
        }
        else if(nums[mid] <= nums[end])
        {
            if(nums[mid] < minm)
            {
                minm = nums[mid];
                idx = mid;
            }
            end = mid-1;
        }      
    }

    return idx;
}

int main()
{
    vector<int> nums = {5,8,9,2,4,6,7};   

    cout << findRotations(nums)<<endl;

    return 0;
}