#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int ans = 0;

    for (int i = 0; i < n1; i++) {
        int st = i, end = n2 - 1;
        int ele = nums1[i];

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (ele <= nums2[mid]) {
                ans = max(abs(i - mid), ans);
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return ans;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1), nums2(n2);

    for (int i = 0; i < n1; i++) cin >> nums1[i];
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    cout << maxDistance(nums1, nums2);
}