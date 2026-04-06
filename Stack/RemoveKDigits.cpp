#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    int n = num.length();
    stack<char> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() > num[i]) {
            if (k > 0) {
                s.pop();
                k--;
            }
            if (k == 0) break;
        }
        s.push(num[i]);
    }

    if (k > 0) {
        while (k--) {
            s.pop();
        }
    }

    string str;
    while (!s.empty()) {
        str.push_back(s.top());
        s.pop();
    }

    reverse(str.begin(), str.end());

    while (!str.empty() && str[0] == '0') {
        str.erase(str.begin());
    }

    if (str.empty()) return "0";
    return str;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    cout << removeKdigits(num, k);
}