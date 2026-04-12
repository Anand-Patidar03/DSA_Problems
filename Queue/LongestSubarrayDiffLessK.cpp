#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    int i = 0, j = 0;
    deque<int> maxm, minm;
    int ans = 0;

    while (j < n) {
        while (!maxm.empty() && nums[maxm.back()] < nums[j]) {
            maxm.pop_back();
        }
        while (!minm.empty() && nums[minm.back()] > nums[j]) {
            minm.pop_back();
        }

        maxm.push_back(j);
        minm.push_back(j);

        while (nums[maxm.front()] - nums[minm.front()] > limit) {
            if (maxm.front() == i) {
                maxm.pop_front();
            }
            if (minm.front() == i) {
                minm.pop_front();
            }
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int main() {
    int n, limit;
    cin >> n >> limit;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << longestSubarray(nums, limit);
}