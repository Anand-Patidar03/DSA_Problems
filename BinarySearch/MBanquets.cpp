#include <bits/stdc++.h>
using namespace std;

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    int maxm = *max_element(bloomDay.begin(), bloomDay.end());
    int minm = *min_element(bloomDay.begin(), bloomDay.end());
    int st = minm, end = maxm, res = -1;

    if ((long long)m * k > n) return -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        int cnt = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                cnt++;
            } else {
                cnt = 0;
            }

            if (cnt == k) {
                ans++;
                if (ans >= m) {
                    break;
                }
                cnt = 0;
            }
        }

        if (ans >= m) {
            end = mid - 1;
            res = mid;
        } else {
            st = mid + 1;
        }
    }

    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++) cin >> bloomDay[i];
    cout << minDays(bloomDay, m, k);
}