#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    int l1 = version1.length();
    int l2 = version2.length();
    int i = 0, j = 0;

    while (i < l1 || j < l2) {
        int num1 = 0, num2 = 0;

        while (i < l1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        while (j < l2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 == num2) {
            i++;
            j++;
        } else if (num1 > num2) {
            return 1;
        } else {
            return -1;
        }
    }

    return 0;
}

int main() {
    string version1, version2;
    cin >> version1 >> version2;
    cout << compareVersion(version1, version2);
}