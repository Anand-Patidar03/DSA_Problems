#include <bits/stdc++.h>
using namespace std;

int grammer(int n, int k) {
    if (n == 1 && k == 1) {
        return 0;
    }

    int mid = pow(2, n - 1) / 2;

    if (k <= mid) {
        return grammer(n - 1, k);
    } else {
        return !grammer(n - 1, k - mid);
    }
}

int kthGrammar(int n, int k) {
    return grammer(n, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << kthGrammar(n, k);
}