#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<pair<int,int>> s;
    vector<int> left;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            left.push_back(-1);
        } else if (s.size() > 0 && s.top().first < heights[i]) {
            left.push_back(s.top().second);
        } else {
            while (s.size() > 0 && s.top().first >= heights[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                left.push_back(-1);
            } else {
                left.push_back(s.top().second);
            }
        }
        s.push({heights[i], i});
    }

    while (!s.empty()) s.pop();

    vector<int> right;

    for (int i = n - 1; i >= 0; i--) {
        if (s.size() == 0) {
            right.push_back(n);
        } else if (s.size() > 0 && s.top().first < heights[i]) {
            right.push_back(s.top().second);
        } else {
            while (s.size() > 0 && s.top().first >= heights[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                right.push_back(n);
            } else {
                right.push_back(s.top().second);
            }
        }
        s.push({heights[i], i});
    }

    reverse(right.begin(), right.end());

    int maxm = INT_MIN;

    for (int i = 0; i < n; i++) {
        int width = (right[i] - left[i] - 1);
        int rect = heights[i] * width;
        maxm = max(maxm, rect);
    }

    return maxm;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    cout << largestRectangleArea(heights);
}