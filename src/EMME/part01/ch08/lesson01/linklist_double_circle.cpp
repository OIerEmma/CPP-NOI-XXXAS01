//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node *prev, *next;
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

int get(node *head, int i) { // 取出双链表的第i个结点的数据域
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

int len(node *head) { // 求双链表的实际长度
    node *p = head->next;
    int ans = 0;
    while (p != head) {
        ans++;
        p = p->next;
    }
    return ans;
}

void insert(node *head, int i, int x) { // 插入一个数据到双向链表中去
    node *p = head, *s;
    int j = 0, flag = 0;
    while((flag == 0 || p != head) && j < i - 1) {
        j++;
        p = p->next;
        if (p == head) {
            flag = 1;
        }
    }
    if (flag == 1 && p == head) {
        cout << "no this position" << endl;
    } else {
        s = new node;
        s->data = x;
        // next方向
        s->next = p->next;
        p->next = s;
        // prev方向
        s->prev = p;
        if (s->next != nullptr) {
            s->next->prev = s;
        }
    }
}

void delete_node(node *head, int i) { // 删除双链表中的第i个结点
    node *p = head, *s;
    int j = 0, flag = 0;
    while ((flag == 0 || p != head) && j < i - 1) {
        j++;
        p = p->next;
        if (p == head) {
            flag = 1;
        }
    }
    if ((flag == 1 && p == head) || head->next == head) {
        cout << "no this position" << endl;
    } else {
        s = p->next;
        p->next = s->next;
        if (s->next != nullptr) {
            s->next->prev = p;
        }
        free(s);
    }
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
    node *head = new node, *r = head; // 尾指针
    int x;
    cin >> x;
    while (x != -1) {
        node *p = new node;
        p->data = x;
        p->next = head;
        r->next = p;
        p->prev = r;
        r = p;
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
    cout << get(head, 1) << endl;
    // 插入函数测试
    insert(head, 1, 40);
    print(head);
    // 删除函数测试
    delete_node(head, 3);
    print(head);
    // 求长度函数测试
    cout << len(head) << endl;
    // 删除函数测试
    delete_node(head, 1);
    print(head);
    // 求长度函数测试
    cout << len(head) << endl;
    return 0;
}
