#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<vector<int>> booking;
    vector<vector<int>> overlap;

    MyCalendarTwo() {
        booking = {};
        overlap = {};
    }
    
    bool book(int startTime, int endTime) {
        for (int j = 0; j < overlap.size(); j++) {
            int maxmm = max(overlap[j][0], startTime);
            int minmm = min(overlap[j][1], endTime);
            if (maxmm < minmm) {
                return false;
            }
        }

        for (int i = 0; i < booking.size(); i++) {
            int maxm = max(booking[i][0], startTime);
            int minm = min(booking[i][1], endTime);
            if (maxm < minm) {
                overlap.push_back({maxm, minm});
            }
        }

        booking.push_back({startTime, endTime});
        return true;
    }
};

int main() {
    MyCalendarTwo obj;

    int q;
    cin >> q;

    while (q--) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        cout << (obj.book(startTime, endTime) ? "true" : "false") << endl;
    }
}