#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void insertEle(stack<int>& s,int ele)
{
    if(s.size() == 0 || s.top() <= ele)
    {
        s.push(ele);
        return;
    }
    int val = s.top();
    s.pop();
    insertEle(s,ele);
    s.push(val);
}

void stSort(stack<int>& s)
{
    if(s.size() == 1)
    {
        return;
    }
    int ele = s.top();
    s.pop();
    stSort(s);
    insertEle(s,ele);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(0);
    s.push(1);
    stSort(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}