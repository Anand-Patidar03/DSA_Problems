#include <bits/stdc++.h>
using namespace std;

void paran(string str, vector<string>& res, int open, int close) {
    if (open == 0 && close == 0) {
        res.push_back(str);
        return;
    }

    if (open > 0) {
        str.push_back('(');
        paran(str, res, open - 1, close);
        str.pop_back();
    }

    if (close > open) {
        str.push_back(')');
        paran(str, res, open, close - 1);
        str.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string str = "";
    paran(str, res, n, n);
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = generateParenthesis(n);

    for (auto &s : ans) cout << s << endl;
}