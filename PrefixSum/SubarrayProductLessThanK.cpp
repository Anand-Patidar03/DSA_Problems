#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, j = 0, count = 0;
    long long mul = 1;

    if (k <= 1) {
        return 0;
    }

    while (j < n) {
        mul *= nums[j];

        while (mul >= k) {
            if (i < n) {
                mul /= nums[i];
            } else {
                break;
            }
            i++;
        }

        int x = j - i + 1;
        count += x;
        j++;
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << numSubarrayProductLessThanK(nums, k);
}