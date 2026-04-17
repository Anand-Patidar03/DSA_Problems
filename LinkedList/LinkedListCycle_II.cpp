#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* temp = head;
    int flag = 0;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        if (fast->next != nullptr)
            fast = fast->next->next;

        if (slow == fast) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        return nullptr;
    }

    while (slow != temp) {
        temp = temp->next;
        slow = slow->next;
    }

    return temp;
}

int main() {
    int n, pos;
    cin >> n >> pos;

    vector<ListNode*> nodes;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nodes.push_back(new ListNode(x));
    }

    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    if (pos != -1) {
        nodes[n - 1]->next = nodes[pos];
    }

    ListNode* head = nodes[0];

    ListNode* res = detectCycle(head);

    if (res == nullptr) cout << -1;
    else cout << res->val;
}