#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    int n = path.length();
    stack<char> s;
    string res = "", str = "";
    int skip_count = 0;

    for (int i = 0; i < n; i++) {
        s.push(path[i]);
    }

    while (s.size() > 0) {
        if (s.top() == '/') {
            s.pop();
        }

        str = "";
        while (s.size() > 0 && s.top() != '/') {
            str.push_back(s.top());
            s.pop();
        }

        if (str == "." || str == "") {
            continue;
        } else if (str == "..") {
            skip_count++;
        } else {
            if (skip_count > 0) {
                skip_count--;
            } else {
                res = "/" + string(str.rbegin(), str.rend()) + res;
            }
        }
    }

    if (res.empty()) return "/";
    return res;
}

int main() {
    string path;
    cin >> path;
    cout << simplifyPath(path);
}