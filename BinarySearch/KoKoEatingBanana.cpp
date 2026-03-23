#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    sort(piles.begin(), piles.end());
    int maxm = piles[n - 1];
    int st = 1, end = maxm, ans = 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil(piles[i] / (double)mid);
        }
        if (sum <= (long long)h) {
            end = mid - 1;
            ans = mid;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) cin >> piles[i];
    cout << minEatingSpeed(piles, h);
}