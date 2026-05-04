#include <bits/stdc++.h>
using namespace std;

void pref(string output, vector<string> &res, int ones, int zeroes)
{
    if (ones == 0 && zeroes == 0)
    {
        res.push_back(output);
        return;
    }

    if (ones > 0)
    {
        pref(output + '1', res, ones - 1, zeroes);
    }

    if (zeroes > 0 && ones < zeroes)
    {
        pref(output + '0', res, ones, zeroes - 1);
    }
}

int main()
{
    int n = 5;
    vector<string> res;

    int ones = n;
    int zeroes = n;

    pref("", res, ones, zeroes);

    for (auto &s : res)
    {
        cout << s << endl;
    }
}