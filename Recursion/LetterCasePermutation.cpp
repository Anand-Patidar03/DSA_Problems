#include <bits/stdc++.h>
using namespace std;

void perm(string input, string output, vector<string>& res) {
    if (input.length() == 0) {
        res.push_back(output);
        return;
    }

    if (input[0] >= '0' && input[0] <= '9') {
        perm(input.substr(1), output + input[0], res);
    } else {
        perm(input.substr(1), output + (char)toupper(input[0]), res);
        perm(input.substr(1), output + (char)tolower(input[0]), res);
    }
}

vector<string> letterCasePermutation(string s) {
    string input = s;
    string output = "";
    vector<string> res;

    perm(input, output, res);
    return res;
}

int main() {
    string s;
    cin >> s;

    vector<string> ans = letterCasePermutation(s);

    for (auto &str : ans) cout << str << endl;
}