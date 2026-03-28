#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int l = j + 1, r = n - 1;

            while (l < r)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                if (sum == target)
                {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                }
                else if (sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
    }

    return res;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ans = fourSum(nums, target);

    for (auto &quad : ans)
    {
        for (auto &x : quad)
            cout << x << " ";
        cout << endl;
    }
}