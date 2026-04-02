#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    vector<int> res;
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--) {
        s.push(nums[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0) {
            res.push_back(-1);
        } else if (s.size() > 0 && s.top() > nums[i]) {
            res.push_back(s.top());
        } else if (s.size() > 0 && s.top() <= nums[i]) {
            while (s.size() > 0 && s.top() <= nums[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                res.push_back(-1);
            } else {
                res.push_back(s.top());
            }
        }
        s.push(nums[i]);
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = nextGreaterElements(nums);

    for (int x : ans) cout << x << " ";
}