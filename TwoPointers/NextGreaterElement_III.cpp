#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n) {
    string s = to_string(n);
    int x = s.length();
    int idx = -1;

    for (int i = x - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return -1;

    for (int i = x - 1; i > idx; i--) {
        if (s[i] > s[idx]) {
            swap(s[i], s[idx]);
            break;
        }
    }

    reverse(s.begin() + idx + 1, s.end());

    long long num = stoll(s);

    if (num > INT_MAX) return -1;
    return num;
}

int main() {
    int n;
    cin >> n;
    cout << nextGreaterElement(n);
}