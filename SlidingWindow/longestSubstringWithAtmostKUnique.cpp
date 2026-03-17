#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abaccab";
    int k=2;

    map<char, int> mp;
    int n = s.length();
    int i = 0, j = 0, maxm = 0;
    while (j < n)
    {
        mp[s[j]]++;
        if(mp.size() <= k)
        {
            maxm = max(maxm,j-i+1);
            j++;
        }
        else 
        {
            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    
    cout<<maxm<<endl;
}