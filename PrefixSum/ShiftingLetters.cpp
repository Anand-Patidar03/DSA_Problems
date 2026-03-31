#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    vector<long long> pref;
    int n = s.length();
    long long sum = 0;
    string res = "";

    for (int i = n - 1; i >= 0; i--) {
        sum += shifts[i];
        pref.push_back(sum);
    }

    reverse(pref.begin(), pref.end());

    for (int i = 0; i < n; i++) {
        int add = pref[i] % 26;
        char ch = ((s[i] - 'a' + add) % 26) + 'a';
        res += ch;
    }

    return res;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;
    vector<int> shifts(n);
    for (int i = 0; i < n; i++) cin >> shifts[i];

    cout << shiftingLetters(s, shifts);
}