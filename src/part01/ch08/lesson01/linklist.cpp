//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
} *head, *p, *r; // r为链表最后一个结点,称为尾指针
int x;

node *find(node *head, int target) { // 查找数据域满足一定条件的结点
    node *p = head->next;
    while (p != nullptr) {
        if (target == p->data) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

int get(node *head, int i) { // 取出单链表的第i个结点的数据域
    node *p = head->next;
    int j = 1;
    while (p != nullptr && j < i) {
        j++;
        p = p->next;
    }
    if (p == nullptr) {
        return -1;
    }
    return p->data;
}

void insert(node *head, int i, int x) { // 插入一个结点到单链表里去
    node *p = head->next, *s;
    int j = 1;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p != nullptr) {
        s = new node;
        s->data = x;
        s->next = p->next;
        p->next = s;
    } else {
        cout << "no this position" << endl;
    }
}

void delete_node(node *head, int i) { // 删除单链表中的第i个结点
    node *p = head, *s;
    int j = 0;
    while (p != nullptr && j < i - 1) {
        j++;
        p = p->next;
    }
    if (p != nullptr && p->next != nullptr) {
        s = p->next;
        p->next = p->next->next; // 或p->next = s->next;
        free(s);
    } else {
        cout << "no this position" << endl;
    }
}

int len(node *head) { // 求单链表的实际长度
    node *p = head->next;
    int ans = 0;
    while (p != nullptr) {
        ans++;
        p = p->next;
    }
    return ans;
}

void print(node *head) {
    node *p = head->next; // 头指针没有数据,只要从第一个结点开始就可以了
    while (p->next != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;  // 最后一个结点单独输出,也可以改用do-while循环
}

int main() {
    cin >> x;
    head = new node; // 申请头结点
    r = head;
    while (x != -1) {
        p = new node; // 申请一个新结点
        p->data = x;
        p->next = nullptr;
        r->next = p; // 把新结点链接到前面的链表中,实际上r是p的直接前趋
        r = p; // 尾指针后移一个
        cin >> x;
    }
    print(head);
    // 查找函数测试
    node *t = find(head, 20);
    if (t != nullptr) {
        cout << t->data << endl;
    } else {
        cout << "no this value" << endl;
    }
    // 取出函数测试
    cout << get(head, 3) << endl;
    // 插入函数测试
    insert(head, 4, 40);
    print(head);
    // 删除函数测试
    delete_node(head, 2);
    print(head);
    // 求长度函数测试
    cout << len(head) << endl;
    return 0;
}
