#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {1, 13, 17, 23};
    int k = 5, n = nums.size();

    vector<int> station(n - 1, 0);
    vector<double> res;
    priority_queue<pair<double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        double diff = (double)(nums[i + 1] - nums[i]);
        pq.push({diff, i});
    }

    for (int i = 0; i < k; i++)
    {
        double maxVal = -1, maxIdx = -1;
        auto tp = pq.top();
        int idx = tp.second;
        pq.pop();
        station[idx]++;
        double diff = (double)(nums[idx + 1] - nums[idx]);
        double dist = diff / (station[idx] + 1);

        pq.push({dist, idx});
    }

    for (int i = 0; i < n - 1; i++)
    {
        res.push_back(nums[i]);

        double gap = (double)(nums[i + 1] - nums[i]) / (station[i] + 1);

        for (int j = 0; j < station[i]; j++)
        {
            res.push_back(nums[i] + (j + 1) * gap);
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << nums[n - 1] << endl;

    return 0;
}