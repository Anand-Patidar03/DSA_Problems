#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    int n = s.size();
    vector<int> lst(26);

    for (int i = 0; i < n; i++) {
        lst[s[i] - 'a'] = i;
    }

    vector<int> res;
    int l = 0;

    while (l < n) {
        int r = lst[s[l] - 'a'];
        int i = l;

        while (i <= r) {
            r = max(r, lst[s[i] - 'a']);
            i++;
        }

        res.push_back(r - l + 1);
        l = r + 1;
    }

    return res;
}

int main() {
    string s;
    cin >> s;

    vector<int> ans = partitionLabels(s);

    for (int x : ans) cout << x << " ";
}