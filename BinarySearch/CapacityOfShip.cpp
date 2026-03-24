#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int sum = 0, maxm = INT_MIN, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += weights[i];
        maxm = max(maxm, weights[i]);
    }
    int st = maxm, end = sum;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        int load = 0, dayreq = 1;
        for (int i = 0; i < n; i++) {
            if (load + weights[i] <= mid) {
                load += weights[i];
            } else {
                dayreq++;
                load = weights[i];
            }
            if (dayreq > days) {
                break;
            }
        }
        if (dayreq <= days) {
            end = mid - 1;
            ans = mid;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, days;
    cin >> n >> days;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    cout << shipWithinDays(weights, days);
}