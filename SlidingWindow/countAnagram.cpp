#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aabaabaa";
    string str = "aaba";
    vector<int> res;

    map<char, int> mp;

    for (char ch : str)
    {
        mp[ch]++;
    }

    int count = mp.size();
    int n = s.length();
    int k = str.length();
    int i = 0, j = 0, ans = 0;
    while (j < n)
    {
        mp[s[j]]--;
        if (mp[s[j]] == 0)
        { 
            count--;
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                //ans++;
                res.push_back(i);
            }
            if (mp[s[i]] == 0)
            {
                count++;
            }
            mp[s[i]]++;

            i++;
            j++;
        }
    }
    // cout << ans << endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}