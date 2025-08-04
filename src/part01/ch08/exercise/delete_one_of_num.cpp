//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void find(node *head, int t) {
    node *p = head->next, *prev = head;
    while (p != nullptr) {
        if (t == p->data) {
            prev->next = p->next;
            free(p);
            p = prev->next;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

int main() {
    int n, x, t;
    node *head = new node, *p, *r = head;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        p = new node;
        p->data = x;
        p->next = nullptr;
        r->next = p;
        r = p;
    }
    cin >> t;
    find(head, t);
    p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}

// 20
// 1 3 3 0 -3 5 6 8 3 10 22 -1 3 5 11 20 100 3 9 3
// 3