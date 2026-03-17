#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3, n = arr.size();
    list<int> l;
    vector<int> ans;

    int i = 0, j = 0;
    while (j < n)
    {
        while (l.size() > 0 && l.back() < arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            if (arr[i] == l.front())
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}