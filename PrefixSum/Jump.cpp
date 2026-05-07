#include <bits/stdc++.h>
using namespace std;

vector<int> maxValue(vector<int>& nums) {
    int n = nums.size();

    vector<int> left(n), right(n), res(n);

    left[0] = nums[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], nums[i]);
    }

    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = min(right[i + 1], nums[i]);
    }

    res[n - 1] = left[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (left[i] > right[i + 1]) {
            res[i] = res[i + 1];
        } else {
            res[i] = left[i];
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = maxValue(nums);

    for (int x : ans) cout << x << " ";
}