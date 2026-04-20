#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    ListNode *start = head, *temp = head;
    int count = 0;

    while (start != nullptr) {
        count++;
        start = start->next;
    }

    int rem = count % k;
    int div = count / k;
    int less = k - rem;
    int more = rem;
    int ls = div;
    int ms = div + 1;

    vector<ListNode*> arr(k);
    start = head;
    ListNode* last = nullptr;

    for (int i = 0; i < more; i++) {
        temp = start;

        for (int j = 0; j < ms; j++) {
            if (start != nullptr) {
                arr[i] = temp;
                last = start;
                start = start->next;
            }
        }

        if (last != nullptr)
            last->next = nullptr;
    }

    for (int i = more; i < less + more; i++) {
        temp = start;

        for (int j = 0; j < ls; j++) {
            if (start != nullptr) {
                arr[i] = temp;
                last = start;
                start = start->next;
            }
        }

        if (last != nullptr)
            last->next = nullptr;

        if (ls == 0) {
            arr[i] = nullptr;
        }
    }

    return arr;
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

void printPart(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ListNode* head = buildList(v);

    vector<ListNode*> parts = splitListToParts(head, k);

    for (auto part : parts) {
        if (part == nullptr) {
            cout << "NULL" << endl;
        } else {
            printPart(part);
        }
    }
}