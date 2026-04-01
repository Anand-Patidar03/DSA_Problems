#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = 1;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int rem = (sum % k + k) % k;
        mp[rem]++;
    }

    int count = 0;

    for (auto x : mp) {
        int f = x.second;
        count += (f * (f - 1)) / 2;
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << subarraysDivByK(nums, k);
}