#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<string> sS;
    stack<int> nS;

    string curr = "";
    int num = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '[') {
            sS.push(curr);
            nS.push(num);
            curr = "";
            num = 0;
        } else if (ch == ']') {
            int repeat = nS.top();
            nS.pop();

            string prev = sS.top();
            sS.pop();

            string temp = "";
            while (repeat--) {
                temp += curr;
            }

            curr = prev + temp;
        } else {
            curr += ch;
        }
    }

    return curr;
}

int main() {
    string s;
    cin >> s;
    cout << decodeString(s);
}