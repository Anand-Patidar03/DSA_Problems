#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    ListNode* start = head;
    ListNode* temp;
    ListNode* curr = head;

    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    int count = 0;
    while (start->next != nullptr) {
        count++;
        start = start->next;
    }
    count++;

    k = k % count;
    if (k == 0) {
        return head;
    }

    int n = count - k - 1;
    while (n--) {
        curr = curr->next;
    }

    temp = curr->next;
    curr->next = nullptr;
    start->next = head;

    return temp;
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
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ListNode* head = buildList(v);
    head = rotateRight(head, k);

    printList(head);
}