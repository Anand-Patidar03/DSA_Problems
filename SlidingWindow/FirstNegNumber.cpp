#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> result;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    for (int i = k; i < n; i++)
    {

        if (!q.empty())
            result.push_back(arr[q.front()]);
        else
            result.push_back(0);

        while (!q.empty() && q.front() <= i - k)
        {
            q.pop();
        }

        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    if (!q.empty())
        result.push_back(arr[q.front()]);
    else
        result.push_back(0);

    return result;
}

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = firstNegativeInWindow(arr, k);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}