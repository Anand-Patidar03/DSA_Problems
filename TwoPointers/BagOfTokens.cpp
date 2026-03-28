#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    int n = tokens.size();
    sort(tokens.begin(), tokens.end());
    int score = 0;
    int l = 0, r = n - 1;

    while (l <= r) {
        if (power >= tokens[l]) {
            score++;
            power -= tokens[l];
            l++;
        } else {
            if (l != r && score > 0) {
                score--;
                power += tokens[r];
                r--;
            } else {
                r--;
            }
        }
    }
    return score;
}

int main() {
    int n, power;
    cin >> n >> power;

    vector<int> tokens(n);
    for (int i = 0; i < n; i++) cin >> tokens[i];

    cout << bagOfTokensScore(tokens, power);
}