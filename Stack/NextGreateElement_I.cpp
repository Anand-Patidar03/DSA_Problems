#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> s;
    vector<int> res;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }

        if (s.empty()) {
            mp[nums2[i]] = -1;
        } else {
            mp[nums2[i]] = s.top();
        }

        s.push(nums2[i]);
    }

    for (int x : nums1) {
        res.push_back(mp[x]);
    }

    return res;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1), nums2(n2);
    for (int i = 0; i < n1; i++) cin >> nums1[i];
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans) cout << x << " ";
}