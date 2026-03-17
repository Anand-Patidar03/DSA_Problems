#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4,1,1,1,2,3,5};
    int k = 5;
    int n = arr.size();

    int i = 0, j = 0, sum = 0, maxm = 0;

    while (j < n)
    {
        if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
        }
        else if (sum < k)
        {
            sum += arr[j];
            j++;
        }
        else
        {
            maxm = max(maxm, j - i);
            sum -= arr[i];
            i++;
        }
    }

    cout << maxm << endl;

    return 0;
}