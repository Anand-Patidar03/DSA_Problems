#include <bits/stdc++.h>
using namespace std;

vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    vector<long long> ans(n, 0);

    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

    for (auto &x : mp) {
        vector<int> &idx = x.second;
        int m = idx.size();

        vector<long long> prefix(m, 0);
        prefix[0] = idx[0];

        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1] + idx[i];
        }

        for (int k = 0; k < m; k++) {
            long long left = 0, right = 0;

            if (k > 0) {
                left = (long long)k * idx[k] - prefix[k - 1];
            }

            if (k < m - 1) {
                right = (prefix[m - 1] - prefix[k]) - (long long)(m - k - 1) * idx[k];
            }

            ans[idx[k]] = left + right;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<long long> ans = distance(nums);

    for (auto x : ans) cout << x << " ";
}