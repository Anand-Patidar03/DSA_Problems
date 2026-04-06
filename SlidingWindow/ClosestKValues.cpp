#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0;
    int mx = INT_MAX;
    vector<int> res;
    pair<int, int> maxm;

    while (j < n) {
        if (j - i + 1 < k) {
            j++;
        } else {
            sum = 0;
            for (int l = i; l <= j; l++) {
                sum += abs(x - arr[l]);
            }

            if (sum < mx) {
                maxm.first = i;
                maxm.second = j;
                mx = sum;
            }

            i++;
            j++;
        }
    }

    for (int i = maxm.first; i <= maxm.second; i++) {
        res.push_back(arr[i]);
    }

    return res;
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = findClosestElements(arr, k, x);

    for (int val : ans) cout << val << " ";
}