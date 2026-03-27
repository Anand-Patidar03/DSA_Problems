#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxm = *max_element(nums.begin(), nums.end());
    int sum = 0;

    if (k > n)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    int st = maxm, end = sum, ans = 0;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        int currSum = 0, ele = 1;

        for (int j = 0; j < n; j++)
        {
            if (currSum + nums[j] <= mid)
            {
                currSum += nums[j];
            }
            else
            {
                ele++;
                currSum = nums[j];
            }
        }

        if (ele <= k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << splitArray(nums, k);
}