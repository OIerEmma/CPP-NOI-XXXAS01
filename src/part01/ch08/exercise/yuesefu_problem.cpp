//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

int main() {
    int n, m;
    while (cin >> n) {
        cin >> m;
        if (n == 0 && m == 0) {
            break;
        }
        int id = 2;
        node *head = new node, *r = head;
        head->data = 1;
        node *p;
        while (id <= n) {
            p = new node;
            p->data = id;
            p->next = head;
            r->next = p;
            r = p;
            id++;
        }
        p = head;
        int j = 0;
        while (j < n) {
            j++;
            int i = 1;
            while (i < m - 1) {
                i++;
                p = p->next;
            }
            p->next = p->next->next;
            p = p->next;
        }
        cout << p->data << endl;
    }
    return 0;
}