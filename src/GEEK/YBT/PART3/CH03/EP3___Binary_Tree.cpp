//
// Created by Geek.Kwok on 2026/3/23.
//
#include <bits/stdc++.h>
using namespace std;

typedef struct node;
typedef node* tree;

struct node {
    char data;
    tree lchild, rchild;
};

// tree bt;

// 1.建立一棵二叉树
void pre_crt(tree &bt) {
    char ch;
    ch = getchar();
    if (ch != '$') {
        bt = new node; // 建根结点
        bt->data = ch;
        pre_crt(bt->lchild); // 建左子树
        pre_crt(bt->rchild); // 建右子树
    }
    else bt = NULL;
}

// 2.删除二叉树
void del(tree &bt) {
    if (bt) {
        del(bt->lchild); // 删左子树
        del(bt->rchild); // 删右子树
        delete bt; // 释放父结点
    }
}

// 3.插入一个结点到排序二叉树中
void insert(tree &bt, int n) {
    if (bt) {
        if (n < bt->data) insert(bt->lchild, n);
        else if (n > bt->data) insert(bt->rchild, n);
    } else {
        bt = new node; // 新开一个空间
        bt->data = n;
        bt->lchild = bt->rchild = NULL;
    }
}

// 4.在排序二叉树中查找一个数，找到返回该结点，否则返回NULL
tree findn(tree bt, int n) {
    if (bt) {
        if (n < bt->data) findn(bt->lchild, n);
        else if (n > bt->data) findn(bt->rchild, n);
        else return bt;
    } else return NULL;
}

// 5.用嵌套括号表示法输出二叉树
void print(tree bt) {
    if (bt) {
        cout << bt->data;
        if (bt->lchild || bt->rchild) {
            cout << '(';
            print(bt->lchild);
            if (bt->rchild) cout << ',';
            print(bt->rchild);
            cout << ')';
        }
    }
}

int main() {

    return 0;
}