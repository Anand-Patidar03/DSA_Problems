#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int allocate(vector<int> &nums, int students)
{
    int n = nums.size();
    int stud;

    if (students > n)
    {
        return -1;
    }

    int maxm = *max_element(nums.begin(), nums.end());

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    int st = maxm, end = sum,ans=0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        int currSum = 0;
        stud = 1;
        for (int j = 0; j < n; j++)
        {
            if (currSum + nums[j] <= mid)
            {
                currSum += nums[j];
            }
            else
            {
                stud++;
                currSum = nums[j];
            }
        }
        if (stud <= students)
        {
            ans = mid;
            end = mid-1;
        }
        else 
        {
            st = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {25, 46, 28, 49, 24};
    int students = 4;

    cout << allocate(nums, students) << endl;

    return 0;
}