#include <bits/stdc++.h>
using namespace std;

int longestBalanced(string s)
{
    string tanqorivel = s;

    int n = s.length();
    int ans = 0, sum = 0;

    unordered_map<int, vector<int>> mp;
    mp[0].push_back(-1);

    int zers = 0, ons = 0;
    for (char c : s)
    {
        if (c == '0')
        {
            zers++;
        }
        else
        {
            ons++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            sum += 1;
        }
        else
        {
            sum -= 1;
        }

        if (mp.count(sum))
        {
            ans = max(ans, i - mp[sum][0]);
        }

        if (mp.count(sum - 2))
        {
            for (int j : mp[sum - 2])
            {
                int L = i - j;
                int zrs = (L - 2) / 2;
                if (zers > zrs)
                {
                    ans = max(ans, L);
                    break;
                }
            }
        }

        if (mp.count(sum + 2))
        {
            for (int j : mp[sum + 2])
            {
                int L = i - j;
                int ones = (L - 2) / 2;
                if (ons > ones)
                {
                    ans = max(ans, L);
                    break;
                }
            }
        }

        if (mp[sum].size() < 2)
        {
            mp[sum].push_back(i);
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << longestBalanced(s);
}