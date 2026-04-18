#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

int pairSum(ListNode* head) {
    stack<int> l, r;

    while (head != nullptr) {
        l.push(head->val);
        head = head->next;
    }

    stack<int> ll = l;
    while (!ll.empty()) {
        r.push(ll.top());
        ll.pop();
    }

    int maxm = 0;

    while (!r.empty()) {
        maxm = max(l.top() + r.top(), maxm);
        l.pop();
        r.pop();
    }

    return maxm;
}

ListNode* buildList(vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int x : v) {
        ListNode* node = new ListNode(x);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ListNode* head = buildList(v);

    cout << pairSum(head);
}