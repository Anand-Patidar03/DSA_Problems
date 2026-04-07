#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;

    vector<int> small(n);
    small[0] = nums[0];

    for (int i = 1; i < n; i++) {
        small[i] = min(small[i - 1], nums[i]);
    }

    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > small[i]) {
            while (!st.empty() && st.top() <= small[i]) {
                st.pop();
            }

            if (!st.empty() && st.top() < nums[i]) {
                return true;
            }

            st.push(nums[i]);
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << (find132pattern(nums) ? "true" : "false");
}