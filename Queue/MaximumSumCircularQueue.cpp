#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    int maxSum = nums[0], minSum = nums[0];
    int maxm = 0, minm = 0;

    for (int i = 0; i < n; i++) {
        maxm = max(nums[i], maxm + nums[i]);
        minm = min(nums[i], minm + nums[i]);

        maxSum = max(maxSum, maxm);
        minSum = min(minSum, minm);
    }

    if (maxSum < 0) {
        return maxSum;
    }

    return max(maxSum, sum - minSum);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << maxSubarraySumCircular(nums);
}