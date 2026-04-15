#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode *ll = head, *rr = head;

    if (left > 1) {
        for (int i = 0; i < left - 2; i++) {
            ll = ll->next;
        }
    }

    ListNode* lf;

    if (left == 1) {
        lf = head;
    } else {
        lf = ll->next;
    }

    for (int i = 0; i < right - 1; i++) {
        rr = rr->next;
    }

    ListNode* last = rr->next;

    ListNode* prev = nullptr;
    ListNode* curr = lf;

    while (curr != last) {
        ListNode* rnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = rnext;
    }

    if (left > 1) {
        ll->next = prev;
    } else {
        head = prev;
    }

    lf->next = last;

    return head;
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
    int n, left, right;
    cin >> n >> left >> right;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ListNode* head = buildList(v);
    head = reverseBetween(head, left, right);
    printList(head);
}