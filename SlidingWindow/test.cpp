#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "TOTMTAPTAT";
    string t = "TTA";
    string res;

    map<char, int> mp;
    for (auto c : t)
        mp[c]++;

    int count = t.length();
    int n = s.length();
    int i = 0, j = 0;
    int minm = INT_MAX;

    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] >= 0)
                count--;
        }

        j++;

        while (count == 0)
        {
            if (j - i < minm)
            {
                minm = j - i;
                res = s.substr(i, j - i);
            }

            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    count++;
            }

            i++;
        }
    }

    cout << minm << endl;
    cout << res << endl;
}