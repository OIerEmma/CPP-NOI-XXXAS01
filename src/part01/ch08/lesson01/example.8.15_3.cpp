//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

struct node {
    int data; // 数据域
    node *next; // 指针域
} *head, *p, *r; // head为头指针,r为尾指针

int main() {
    int n, m;
    cin >> n >> m;
    head = new node; // 为head申请一个新内存空间
    head->data = 1; // head头指针里就有真正的数据了,说明此链表为无头链表
    head->next = nullptr; // 初始化head头指针的下一个
    r = head; // 初始化尾指针
    for (int i = 2; i <= n; i++) {
        p = new node; // 申请一块新内存空间
        p->data = i; // 保存链表值
        p->next = nullptr;
        r->next = p;
        r = p; // 更新尾指针
    }
    r->next = head; // 将链表变为循环链表,就是把尾指针指向头指针
    r = head;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 2; j++) {
            r = r->next;
        }
        cout << r->next->data << " "; // 输出数据
        r->next = r->next->next; // 删除报到n的人
        r = r->next; // r尾指针指到下一项
    }
    return 0;
}
