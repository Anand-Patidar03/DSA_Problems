#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "a";
    string t = "a";
    string res="";

    map<char, int> mp;
    for (auto c : t)
    {
        mp[c]++;
    }
    int count = mp.size();
    int n = s.length();
    int i = 0, j = 0, minm = INT_MAX,start=0;
    while (j < n)
    {
        if (count > 0)
        {
            if (mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    count--;
                }
            }
            j++;
        }
        if (count == 0)
        {
            while (count == 0)
            {
                if (j - i < minm)
                {
                    minm = j - i;
                    start = i;
                }
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0)
                    {
                        count++;
                    }
                }
                i++;
            }
            res = s.substr(start,minm);
        }
    }

    cout << minm << endl;
    cout << res << endl;
}