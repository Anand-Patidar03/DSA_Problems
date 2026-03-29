#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefSum;

    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                prefSum[i][j] = matrix[i - 1][j - 1] + prefSum[i - 1][j] + prefSum[i][j - 1] - prefSum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefSum[row2 + 1][col2 + 1] - prefSum[row1][col2 + 1] - prefSum[row2 + 1][col1] + prefSum[row1][col1];
        return sum;
    }
};

int main() {
    int m = 5, n = 5;

    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix obj(matrix);

    int row1 = 2, col1 = 1, row2 = 4, col2 = 3;
    cout << obj.sumRegion(row1, col1, row2, col2) << endl;
}