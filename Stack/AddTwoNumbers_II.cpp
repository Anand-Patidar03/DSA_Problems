#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2, s3;

    while (l1 != nullptr) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int car = 0;

    while (!s1.empty() && !s2.empty()) {
        int sum = s1.top() + s2.top() + car;
        int rem = sum % 10;
        int div = sum / 10;
        s3.push(rem);
        car = div;
        s1.pop();
        s2.pop();
    }

    while (!s1.empty()) {
        int sum = s1.top() + car;
        int rem = sum % 10;
        int div = sum / 10;
        s3.push(rem);
        car = div;
        s1.pop();
    }

    while (!s2.empty()) {
        int sum = s2.top() + car;
        int rem = sum % 10;
        int div = sum / 10;
        s3.push(rem);
        car = div;
        s2.pop();
    }

    if (car > 0) {
        s3.push(car);
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (!s3.empty()) {
        ListNode* node = new ListNode(s3.top());

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        s3.pop();
    }

    return head;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> v1(n1), v2(n2);
    for (int i = 0; i < n1; i++) cin >> v1[i];
    for (int i = 0; i < n2; i++) cin >> v2[i];

    ListNode* l1 = buildList(v1);
    ListNode* l2 = buildList(v2);

    ListNode* result = addTwoNumbers(l1, l2);
    printList(result);
}