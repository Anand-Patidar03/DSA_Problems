#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    vector<int> q;
    int front;
    int rear, k;

    MyCircularQueue(int k)
    {
        q = vector<int>(k);
        this->k = k;
        front = -1;
        rear = -1;
    }

    bool enQueue(int value)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            q[rear] = value;
        }
        else
        {
            if ((rear + 1) % k == front)
            {
                return false;
            }
            rear = (rear + 1) % k;
            q[rear] = value;
        }
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
        {
            return false;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % k;
        }
        return true;
    }

    int Front()
    {
        if (front == -1)
            return -1;
        return q[front];
    }

    int Rear()
    {
        if (front == -1)
            return -1;
        return q[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % k == front;
    }
};

int main()
{
    int k;
    cin >> k;

    MyCircularQueue obj(k);

    int q;
    cin >> q;

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "enQueue")
        {
            int value;
            cin >> value;
            cout << (obj.enQueue(value) ? "true" : "false") << endl;
        }
        else if (op == "deQueue")
        {
            cout << (obj.deQueue() ? "true" : "false") << endl;
        }
        else if (op == "Front")
        {
            cout << obj.Front() << endl;
        }
        else if (op == "Rear")
        {
            cout << obj.Rear() << endl;
        }
        else if (op == "isEmpty")
        {
            cout << (obj.isEmpty() ? "true" : "false") << endl;
        }
        else if (op == "isFull")
        {
            cout << (obj.isFull() ? "true" : "false") << endl;
        }
    }
}