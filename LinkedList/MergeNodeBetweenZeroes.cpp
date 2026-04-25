#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode* start = head;
    long long sum = 0;

    ListNode* st = nullptr;
    ListNode* tail = nullptr;

    while (start != nullptr) {
        if (start->val == 0) {
            ListNode* newNode = new ListNode(sum);

            if (st == nullptr) {
                st = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            sum = 0;
            start = start->next;
            continue;
        }

        sum += start->val;
        start = start->next;
    }

    return st->next;
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

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ListNode* head = buildList(v);
    ListNode* res = mergeNodes(head);

    printList(res);
}