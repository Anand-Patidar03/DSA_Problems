#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* left = head;
    ListNode* right = left->next;

    if (right == nullptr) {
        return head;
    }

    while (right != nullptr) {
        int ele = __gcd(left->val, right->val);
        ListNode* newNode = new ListNode(ele);

        left->next = newNode;
        newNode->next = right;

        left = right;
        right = right->next;
    }

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
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ListNode* head = buildList(v);
    head = insertGreatestCommonDivisors(head);
    printList(head);
}