#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue
{
public:
    deque<int> dq;

    FrontMiddleBackQueue() {}

    void pushFront(int val)
    {
        dq.push_front(val);
    }

    void pushMiddle(int val)
    {
        auto mid = dq.size() / 2;
        dq.insert(dq.begin() + mid, val);
    }

    void pushBack(int val)
    {
        dq.push_back(val);
    }

    int popFront()
    {
        if (dq.empty())
            return -1;
        int ele = dq.front();
        dq.pop_front();
        return ele;
    }

    int popMiddle()
    {
        if (dq.empty())
            return -1;
        auto mid = (dq.size() - 1) / 2;
        int ele = dq[mid];
        dq.erase(dq.begin() + mid);
        return ele;
    }

    int popBack()
    {
        if (dq.empty())
            return -1;
        int ele = dq.back();
        dq.pop_back();
        return ele;
    }
};

int main()
{
    FrontMiddleBackQueue obj;

    int q;
    cin >> q;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "pushFront")
        {
            int val;
            cin >> val;
            obj.pushFront(val);
        }
        else if (op == "pushMiddle")
        {
            int val;
            cin >> val;
            obj.pushMiddle(val);
        }
        else if (op == "pushBack")
        {
            int val;
            cin >> val;
            obj.pushBack(val);
        }
        else if (op == "popFront")
        {
            cout << obj.popFront() << endl;
        }
        else if (op == "popMiddle")
        {
            cout << obj.popMiddle() << endl;
        }
        else if (op == "popBack")
        {
            cout << obj.popBack() << endl;
        }
    }
}