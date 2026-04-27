#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void reverseSt(stack<int>& s,stack<int>& rev)
{
    if(s.size() == 0)
    {
        return;
    }

    int val = s.top();
    s.pop();
    rev.push(val);
    reverseSt(s,rev);
    
}

int main()
{
    stack<int> s,rev;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseSt(s,rev);

    while (!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }

    return 0;
}