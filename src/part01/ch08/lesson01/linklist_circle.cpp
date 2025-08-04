//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *find(node *head, int target) { // 查找数据域满足一定条件的结点
    node *p = head->next;
    while (p != head) {
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
    while (p != head && j < i) {
        j++;
        p = p->next;
    }
    if (p == head) {
        return -1;
    }
    return p->data;
}

void insert(node *head, int i, int x) { // 插入一个结点到单链表里去
    node *p = head, *s;
    int j = 0, flag = 0;
    while ((flag == 0 || p != head) && j < i - 1) {
        p = p->next;
        j++;
        if (p == head) {
            flag = 1;
        }
    }
    if (flag == 0 || p != head) {
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
    int j = 0, flag = 0;
    while ((flag == 0 || p != head) && j < i - 1) {
        j++;
        p = p->next;
        if (p == head) {
            flag = 1;
        }
    }
    if ((flag == 0 || p != head) && p->next != head) {
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
    while (p != head) {
        ans++;
        p = p->next;
    }
    return ans;
}

void print(node *head) {
    if (head->next == head) {
        cout << "empty linklist" << endl;
        return;
    }
    node *p = head->next; // 头指针没有数据,只要从第一个结点开始就可以了
    while (p->next != head) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;  // 最后一个结点单独输出,也可以改用do-while循环
}

int main() {
    int x;
    node *head, *p, *r;
    cin >> x;
    head = new node; // 申请头结点
    head->next = head;
    r = head;
    while (x != -1) {
        p = new node; // 申请一个新结点
        p->data = x;
        p->next = head;
        r->next = p; // 把新结点链接到前面的链表中,实际上r是p的直接前趋
        r = p; // 尾指针后移一个
        cin >> x;
    }
    print(head);
    // 取出函数测试
    cout << get(head, 1) << endl;
    cout << get(head, 5) << endl;
    cout << get(head, 2) << endl;
    // 插入函数测试
    insert(head, 1, 40);
    print(head);
    insert(head, 6, 20);
    print(head);
    insert(head, 4, 30);
    print(head);
    // 删除函数测试
    delete_node(head, 1);
    print(head);
    delete_node(head, 7);
    print(head);
    delete_node(head, 3);
    print(head);
    delete_node(head, 1);
    print(head);
    delete_node(head, 1);
    print(head);
    // delete_node(head, 1);
    // print(head);
    // delete_node(head, 1);
    // print(head);
    // delete_node(head, 1);
    // print(head);
    // delete_node(head, 1);
    // print(head);
    // 求长度函数测试
    cout << len(head) << endl;
    return 0;
}
