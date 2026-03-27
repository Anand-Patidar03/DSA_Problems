#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int idx1 = (n + m) / 2, idx2 = idx1 - 1;
    int i = 0, j = 0;
    int cnt = 0, fele = -1, sele = -1;

    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            if (cnt == idx2)
                fele = nums1[i];
            else if (cnt == idx1)
                sele = nums1[i];
            i++;
            cnt++;
        }
        else
        {
            if (cnt == idx2)
                fele = nums2[j];
            else if (cnt == idx1)
                sele = nums2[j];
            j++;
            cnt++;
        }
    }

    while (i < n)
    {
        if (cnt == idx2)
            fele = nums1[i];
        else if (cnt == idx1)
            sele = nums1[i];
        i++;
        cnt++;
    }

    while (j < m)
    {
        if (cnt == idx2)
            fele = nums2[j];
        else if (cnt == idx1)
            sele = nums2[j];
        j++;
        cnt++;
    }

    if ((n + m) % 2 == 0)
    {
        return (double)(fele + sele) / 2.0;
    }
    else
    {
        return (double)(sele);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < m; i++)
        cin >> nums2[i];
    cout << findMedianSortedArrays(nums1, nums2);
}