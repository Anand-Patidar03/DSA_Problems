#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int n = s.length();
    int maxLen = 0;

    for (int l = 1; l <= 26; l++) {
        vector<int> freq(26, 0);
        int i = 0, j = 0;
        int cnt = 0;
        int K = 0;

        while (j < n) {
            if (freq[s[j] - 'a'] == 0) {
                cnt++;
            }
            freq[s[j] - 'a']++;

            if (freq[s[j] - 'a'] == k) {
                K++;
            }

            while (cnt > l) {
                if (freq[s[i] - 'a'] == k) {
                    K--;
                }
                freq[s[i] - 'a']--;

                if (freq[s[i] - 'a'] == 0) {
                    cnt--;
                }
                i++;
            }

            if (cnt == l && K == l) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }
    }

    return maxLen;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << longestSubstring(s, k);
}