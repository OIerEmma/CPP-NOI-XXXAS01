//
// Created by Geek.Kwok on 2026/3/24.
//
#include <bits/stdc++.h>
using namespace std;

typedef struct node;
typedef node* tree;

struct node {
    char data;
    tree lchild, rchild;
};
tree bt;
int i;
string s;

void build(tree &bt) {
    if (s[++i] != '.') {
        bt = new node;
        bt->data = s[i];
        build(bt->lchild);
        build(bt->rchild);
    } else bt = NULL;
}

void printzx(tree bt) {
    if (bt) {
        printzx(bt->lchild);
        cout << bt->data;
        printzx(bt->rchild);
    }
}

void printhx(tree bt) {
    if (bt) {
        printhx(bt->lchild);
        printhx(bt->rchild);
        cout << bt->data;
    }
}

int main() {
    // freopen("tree_b.in", "r", stdin);
    // freopen("tree_b.out", "w", stdout);
    cin >> s;
    i = -1;
    build(bt);
    printzx(bt);
    cout << endl;
    printhx(bt);
    cout << endl;
    return 0;
}