#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int x = matrix.size();
    int y = matrix[0].size();

    int st = 0, end = x - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (target < matrix[mid][0]) {
            end = mid - 1;
        } else if (target > matrix[mid][0] && target > matrix[mid][y - 1]) {
            st = mid + 1;
        } else {
            int low = 0, high = y - 1;

            while (low <= high) {
                int m = low + (high - low) / 2;

                if (target < matrix[mid][m]) {
                    high = m - 1;
                } else if (target > matrix[mid][m]) {
                    low = m + 1;
                } else {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

int main() {
    int m, n, target;
    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << (searchMatrix(matrix, target) ? "true" : "false");
}