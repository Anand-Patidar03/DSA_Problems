#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;

    if (head == nullptr || k == 1) {
        return head;
    }

    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    int num = count / k;

    ListNode dummy(0);
    dummy.next = head;

    ListNode* groupPrev = &dummy;

    while (num--) {
        ListNode* prev = nullptr;
        ListNode* curr = groupPrev->next;
        ListNode* groupStart = curr;
        ListNode* rnext;
        int n = k;

        while (n--) {
            rnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = rnext;
        }

        groupPrev->next = prev;
        groupStart->next = curr;

        groupPrev = groupStart;
    }

    return dummy.next;
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
    head = reverseKGroup(head, k);

    printList(head);
}