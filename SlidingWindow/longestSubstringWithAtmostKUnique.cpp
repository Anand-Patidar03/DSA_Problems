#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRemovals(vector<int> &nums, int target)
    {
        int n = nums.size();

        int xorr = 0;
        for (int x : nums)
        {
            xorr ^= x;
        }

        int X = xorr ^ target;

        if (X == 0)
        {
            return 0;
        }

        unordered_set<int> s(nums.begin(), nums.end());

        if (s.count(X))
        {
            return 1;
        }

        for (int x : nums)
        {
            int req = X ^ x;
            if (req != x && s.count(req))
            {
                return 2;
            }
        }

        return -1;
    }
};