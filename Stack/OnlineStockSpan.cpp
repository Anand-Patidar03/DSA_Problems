#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s;

    StockSpanner() {}

    int next(int price) {
        int count = 1;
        while (s.size() > 0 && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count});
        return count;
    }
};

int main() {
    StockSpanner obj;

    int q;
    cin >> q;

    while (q--) {
        int price;
        cin >> price;
        cout << obj.next(price) << endl;
    }
}