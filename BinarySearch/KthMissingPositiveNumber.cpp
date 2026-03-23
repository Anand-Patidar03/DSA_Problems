#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> miss(n);
    for (int i = 0; i < n; i++) {
        miss[i] = arr[i] - i - 1;
    }

    int st = 0, end = n - 1;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (miss[mid] < k) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return k + st;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << findKthPositive(arr, k);
}