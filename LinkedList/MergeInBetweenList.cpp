#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* start = list1;
    ListNode* st = list1;
    ListNode* last = list2;

    int n = a - 1;
    int l = b;

    while (n--) {
        start = start->next;
    }

    while (l--) {
        st = st->next;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    start->next = list2;
    last->next = st->next;

    return list1;
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
    int n1, n2, a, b;
    cin >> n1 >> n2 >> a >> b;

    vector<int> v1(n1), v2(n2);
    for (int i = 0; i < n1; i++) cin >> v1[i];
    for (int i = 0; i < n2; i++) cin >> v2[i];

    ListNode* list1 = buildList(v1);
    ListNode* list2 = buildList(v2);

    ListNode* res = mergeInBetween(list1, a, b, list2);
    printList(res);
}