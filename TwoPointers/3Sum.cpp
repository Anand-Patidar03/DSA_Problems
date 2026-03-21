#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2;) {
        int ele = nums[i];
        int sum = 0 - ele;
        int l = i + 1, r = n - 1;

        while (l < r) {
            if (nums[l] + nums[r] < sum) {
                l++;
            } else if (nums[l] + nums[r] > sum) {
                r--;
            } else {
                res.push_back({nums[l], nums[r], ele});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }

        int idx = i + 1;
        while (idx < n && nums[idx] == nums[i]) idx++;
        i = idx;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> ans = threeSum(nums);

    for (auto &triplet : ans) {
        for (auto &x : triplet) cout << x << " ";
        cout << endl;
    }
}