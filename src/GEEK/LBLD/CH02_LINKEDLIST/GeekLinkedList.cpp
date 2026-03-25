//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 输入一个数组，转换为一条单链表
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    if (head == nullptr) { return; }
    // 遍历单链表
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p -> val << " ";
    }
    cout << endl;
}

int main() {
    // 查/改：单链表的遍历/查找/修改
    // 创建一条单链表
    ListNode* head = createLinkedList({1, 2, 3, 4, 5});
    // 遍历单链表
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p -> val << " ";
    }
    cout << endl;

    // 增 //
    // 在单链表头部插入新元素（与数组比较一下复杂度）
    // 在单链表头部插入一个新节点0
    ListNode* newNode = new ListNode(0);
    newNode -> next = head;
    head = newNode;

    // 现在链表变成了 0 -> 1 -> 2 -> 3 -> 4 -> 5
    printLinkedList(head);

    // 在单链表尾部插入新元素
    // 在单量表尾部插入一个新节点6
    ListNode* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    // 现在p就是链表的最后一个节点 在p后面插入新节点
    p->next = new ListNode(6);
    // 现在链表变成了 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
    printLinkedList(head);

    // 在单链表中间插入新元素
    // 在第3个节点后面插入一个新节点66
    // 先要找到前驱节点，即第3个节点
    ListNode* p1 = head;
    for (int i = 0; i < 2; i++) {
        p1 = p1->next;
    }
    // 此时p指向第3个节点
    // 组装新节点的后驱指针
    ListNode* newNode1 = new ListNode(66);
    newNode1->next = p1->next;
    // 插入新节点
    p1->next = newNode1;
    // 现在链表变成了 0 -> 1 -> 2 -> 66 -> 3 -> 4 -> 5 -> 6
    printLinkedList(head);

    // 删 //
    // 在单链表中删除一个节点
    // 删除第4个节点，要操作前驱节点
    ListNode* p2 = head;
    for (int i = 0; i < 2; i++) {
        p = p->next;
    }
    // 此时p指向第3个节点，即要删除节点的前驱节点
    // 把第4个节点从链表中摘除
    p->next = p->next->next;
    // 现在链表变成了 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
    printLinkedList(head);

    // 在单链表尾部删除元素
    // 删除尾节点
    ListNode* p3 = head;
    // 找到倒数第二个节点
    while (p3->next->next != nullptr) {
        p3 = p3->next;
    }
    // 此时p指向倒数第二个节点
    // 把尾节点从链表中摘除
    p3->next = nullptr;
    // 现在链表变成了 0 -> 1 -> 2 -> 3 -> 4 -> 5
    printLinkedList(head);

    // 在单链表头部删除元素
    // 删除头结点
    head = head->next;
    // 现在链表变成了 1 -> 2 -> 3 -> 4 -> 5
    printLinkedList(head);

    return 0;
}