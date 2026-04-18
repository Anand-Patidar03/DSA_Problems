#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> mp;
    Node* temp = head;

    while (temp != nullptr) {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes[i] = new Node(val);
    }

    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    vector<int> randomIdx(n);
    for (int i = 0; i < n; i++) cin >> randomIdx[i];

    for (int i = 0; i < n; i++) {
        if (randomIdx[i] != -1) {
            nodes[i]->random = nodes[randomIdx[i]];
        }
    }

    Node* head = nodes[0];
    Node* copied = copyRandomList(head);

    Node* temp = copied;
    while (temp) {
        cout << temp->val << " ";
        if (temp->random) cout << temp->random->val << " ";
        else cout << -1 << " ";
        temp = temp->next;
    }
}