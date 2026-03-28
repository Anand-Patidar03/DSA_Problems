#include <bits/stdc++.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int maxCount = INT_MIN, row = -1;

    for (int i = 0; i < m; i++) {
        sort(mat[i].begin(), mat[i].end());
    }

    for (int i = 0; i < m; i++) {
        int st = 0, end = n - 1;
        int idx = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (mat[i][mid] == 1) {
                end = mid - 1;
                idx = mid;
            } else {
                st = mid + 1;
            }
        }

        if (n - idx > maxCount) {
            maxCount = n - idx;
            row = i;
        }
    }

    return {row, maxCount};
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = rowAndMaximumOnes(mat);
    cout << ans[0] << " " << ans[1];
}