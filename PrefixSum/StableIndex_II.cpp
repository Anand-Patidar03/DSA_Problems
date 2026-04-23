#include <bits/stdc++.h>
using namespace std;

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> prefMax(n), prefMin(n);

    prefMax[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefMax[i] = max(prefMax[i - 1], nums[i]);
    }

    prefMin[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        prefMin[i] = min(prefMin[i + 1], nums[i]);
    }

    for (int i = 0; i < n; i++) {
        if (prefMax[i] - prefMin[i] <= k) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << firstStableIndex(nums, k);
}