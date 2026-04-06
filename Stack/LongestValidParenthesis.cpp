#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.length();
    stack<int> st;
    st.push(-1);
    int len = 0, maxm = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) st.pop();
            if (st.size() == 0) {
                st.push(i);
            } else {
                len = i - st.top();
                maxm = max(maxm, len);
            }
        }
    }

    return maxm;
}

int main() {
    string s;
    cin >> s;
    cout << longestValidParentheses(s);
}