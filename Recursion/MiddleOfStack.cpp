#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

stack<int> findMid(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return s;
    }

    int val = s.top();
    s.pop();
    findMid(s, k - 1);
    s.push(val);
    return s;
}

int main()
{
    stack<int> s, s1;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s1 = s;
    int n = 0;
    while (!s1.empty())
    {
        n++;
        s1.pop();
    }

    s = findMid(s, n / 2 + 1);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}