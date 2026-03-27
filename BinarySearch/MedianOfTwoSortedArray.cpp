#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int st = 0, end = n, left = (n + m + 1) / 2;

    while (st <= end) {
        int mid1 = st + (end - st) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
        if (mid1 < n) r1 = nums1[mid1];
        if (mid2 < m) r2 = nums2[mid2];

        if (l1 <= r2 && l2 <= r1) {
            if ((n + m) % 2 == 1) {
                return max(l1, l2);
            } else {
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
        } else if (l2 > r1) {
            st = mid1 + 1;
        } else {
            end = mid1 - 1;
        }
    }

    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < m; i++) cin >> nums2[i];

    cout << findMedianSortedArrays(nums1, nums2);
}