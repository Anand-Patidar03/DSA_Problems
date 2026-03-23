#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end());
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        int sum = people[l] + people[r];
        if (sum <= limit) {
            ans++;
            l++;
            r--;
        } else {
            ans++;
            r--;
        }
    }
    return ans;
}

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> people(n);
    for (int i = 0; i < n; i++) cin >> people[i];
    cout << numRescueBoats(people, limit);
}