#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> b(n), a(n), res;
    b[0] = 1;
    a[n - 1] = 1;

    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        a[i] = a[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
        res.push_back(a[i] * b[i]);
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = productExceptSelf(nums);

    for (int x : ans) cout << x << " ";
}