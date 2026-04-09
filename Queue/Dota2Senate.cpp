#include <bits/stdc++.h>
using namespace std;

string predictPartyVictory(string senate) {
    int n = senate.length();
    queue<int> R, D;

    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            R.push(i);
        } else {
            D.push(i);
        }
    }

    while (!R.empty() && !D.empty()) {
        if (R.front() < D.front()) {
            D.pop();
            int ele = R.front();
            R.pop();
            R.push(ele + n);
        } else {
            R.pop();
            int ele = D.front();
            D.pop();
            D.push(ele + n);
        }
    }

    if (R.empty()) return "Dire";
    return "Radiant";
}

int main() {
    string senate;
    cin >> senate;
    cout << predictPartyVictory(senate);
}