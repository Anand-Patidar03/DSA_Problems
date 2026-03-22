#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    int max_len = 0;
    string res = "";

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int l = i, r = j;
            int flag = 1;

            while (l <= r) {
                if (s[l] != s[r]) {
                    flag = 0;
                    break;
                }
                l++;
                r--;
            }

            if (flag == 1) {
                int len = j - i + 1;
                if (len > max_len) {
                    max_len = len;
                    res = s.substr(i, len);
                }
            }
        }
    }

    return res;
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}