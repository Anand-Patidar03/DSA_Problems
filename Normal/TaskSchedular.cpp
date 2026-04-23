#include <bits/stdc++.h>
using namespace std;

long long taskSchedulerII(vector<int>& tasks, int space) {
    int n = tasks.size();
    unordered_map<int, long long> mp;
    long long time = 0;

    for (int i = 0; i < n; i++) {
        time++;

        if (mp.find(tasks[i]) == mp.end()) {
            mp[tasks[i]] = time;
        } else {
            if ((time - mp[tasks[i]]) <= space) {
                time = mp[tasks[i]] + space + 1;
            }
            mp[tasks[i]] = time;
        }
    }

    return time;
}

int main() {
    int n, space;
    cin >> n >> space;

    vector<int> tasks(n);
    for (int i = 0; i < n; i++) cin >> tasks[i];

    cout << taskSchedulerII(tasks, space);
}