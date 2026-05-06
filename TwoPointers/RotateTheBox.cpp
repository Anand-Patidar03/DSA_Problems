#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int m = boxGrid.size();
    int n = boxGrid[0].size();

    if (n >= 2) {
        for (int i = 0; i < m; i++) {
            int j = n - 1, k = n - 2;

            while (k >= 0) {
                if (boxGrid[i][k] == '*') {
                    k--;
                    j = k;
                    k--;
                }
                else if (boxGrid[i][k] == '#' && boxGrid[i][j] == '.') {
                    swap(boxGrid[i][k], boxGrid[i][j]);
                    j--;
                    k--;
                }
                else if (boxGrid[i][k] == '.' && boxGrid[i][j] == '.') {
                    k--;
                }
                else {
                    j--;
                    k--;
                }
            }
        }
    }

    vector<vector<char>> ans(n, vector<char>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][m - 1 - i] = boxGrid[i][j];
        }
    }

    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> boxGrid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> boxGrid[i][j];
        }
    }

    vector<vector<char>> ans = rotateTheBox(boxGrid);

    for (auto &row : ans) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
}