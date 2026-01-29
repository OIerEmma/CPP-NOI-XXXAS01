//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

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
    cout << p->data << endl; // 最后一个结点单独输出,也可以改用do-while循环
}

int main() {
    int m, n, id = 1;
    cin >> m >> n;
    node *head = new node, *p, *r = head;
    // 构建单循环链表
    while (id <= m) {
        p = new node;
        p->data = id;
        p->next = head;
        r->next = p;
        r = p;
        id++;
    }
    print(head);
    // 模拟报数过程
    p = head->next;
    while (head->next != head) {
        // 1.走个n步第1遍
        int i = 1;
        while (i < n - 1) {
            i++;
            p = p->next;
            // 确保p指针移动后不会停留在head指针
            if (p == head) {
                p = p->next;
            }
        }
        // 确保p指针移动后不会停留在head指针
        if (p->next == head) {
            p = p->next;
        }
        cout << p->next->data << " ";
        // 2.删除 a -> b -> c  删除b：a.next = a.next.next
        if (p->next != head) {
            p->next = p->next->next;
            // p
            p = p->next;
        } else {
            p = p->next->next;
        }
        // 确保p指针移动后不会停留在head指针
        if (p == head) {
            p = p->next;
        }
    }
    return 0;
}
