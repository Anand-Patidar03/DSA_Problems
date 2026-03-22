#include <bits/stdc++.h>
using namespace std;

int numSubseq(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0, r = n - 1, ans = 0;
    int mod = 1e9 + 7;
    vector<int> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 2) % mod;
    }
    while (l <= r) {
        int sum = nums[l] + nums[r];
        if (sum > target) {
            r--;
        } else {
            ans = (ans + power[r - l]) % mod;
            l++;
        }
    }
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << numSubseq(nums, target);
}