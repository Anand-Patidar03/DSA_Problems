#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int st = 1, end = *max_element(nums.begin(), nums.end()), res = 0;
    if (threshold == n) return *max_element(nums.begin(), nums.end());

    while (st <= end) {
        int mid = st + (end - st) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int div = ceil(nums[i] / (double)mid);
            sum += div;
            if (sum > threshold) {
                break;
            }
        }
        if (sum > threshold) {
            st = mid + 1;
        } else {
            end = mid - 1;
            res = mid;
        }
    }
    return res;
}

int main() {
    int n, threshold;
    cin >> n >> threshold;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << smallestDivisor(nums, threshold);
}