#include <bits/stdc++.h>
using namespace std;

int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    deque<pair<int, int>> dq;
    long long ans = LLONG_MIN;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        int x = points[i][0], y = points[i][1];

        while (!dq.empty() && x - dq.front().first > k)
        {
            dq.pop_front();
        }

        if (!dq.empty())
        {
            ans = max(ans, (long long)(y + x + dq.front().second));
        }

        int ele = y - x;
        while (!dq.empty() && dq.back().second <= ele)
        {
            dq.pop_back();
        }

        dq.push_back({x, ele});
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    cout << findMaxValueOfEquation(points, k);
}