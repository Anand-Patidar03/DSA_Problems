#include <bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    deque<int> dq;
    int n = deck.size();

    sort(deck.begin(), deck.end());
    dq.push_front(deck[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        int ele = dq.back();
        dq.pop_back();
        dq.push_front(ele);
        dq.push_front(deck[i]);
    }

    vector<int> res;

    while (!dq.empty()) {
        res.push_back(dq.front());
        dq.pop_front();
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> deck(n);
    for (int i = 0; i < n; i++) cin >> deck[i];

    vector<int> ans = deckRevealedIncreasing(deck);

    for (int x : ans) cout << x << " ";
}