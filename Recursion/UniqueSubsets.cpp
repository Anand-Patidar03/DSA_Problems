#include <bits/stdc++.h>
using namespace std;

void subs(int i, vector<int> &nums, vector<int> &curr, set<vector<int>> &res)
{
    if (i == nums.size())
    {
        res.insert(curr);
        return;
    }

    // pick
    curr.push_back(nums[i]);
    subs(i + 1, nums, curr, res);

    // not pick
    curr.pop_back();
    subs(i + 1, nums, curr, res);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    set<vector<int>> res;
    vector<int> curr;

    sort(nums.begin(), nums.end()); 

    subs(0, nums, curr, res);

    return vector<vector<int>>(res.begin(), res.end());
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ans = subsets(nums);

    for (auto &vec : ans)
    {
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
}