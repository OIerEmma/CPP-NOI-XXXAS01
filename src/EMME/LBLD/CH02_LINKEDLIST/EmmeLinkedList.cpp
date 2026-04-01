//
// Created by Emme.Kwok on 2026/3/31.
//
#include<iostream>
#include<vector>
using namespace std;

template<typename E>

class ListNode{
public:
    E val;
    ListNode* next;
    ListNode* prev;
    ListNode(E x) : val(x), next(nullptr) {}
    ListNode(ListNode* prev, E element, ListNode* next) {
        this->val = element;
        this->prev = prev;
        this->next = next;
    }
};
// 输入一个数组，转换为一条单链表
ListNode<int>* createLinkedList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode<int>* head = new ListNode<int>(arr[0]);
    ListNode<int>* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode<int>(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printLinkedList(ListNode<int>* head) {
    if (head == nullptr) return;
    for (ListNode<int>* p = head; p != nullptr; p = p->next) cout << p->val << " ";
    cout << endl;
}

int main() {
    // 创建一个单链表
    ListNode<int>* head = createLinkedList({1, 2, 3, 4, 5});
    // 查或改
    // 遍历单链表
    for (ListNode<int>* p = head; p != nullptr; p = p->next) cout << p->val << " ";
    cout << endl;
    // 增
    // 1.在单链表头部插入一个新节点0
    ListNode<int>* newNode = new ListNode<int>(0);
    newNode->next = head;
    head = newNode;
    printLinkedList(head);
    // 现在的链表：0 -> 1 -> 2 -> 3 -> 4 -> 5
    // 2.在单链表尾部插入一个新节点6
    ListNode<int>* p = head;
    // 先走到链表的最后一个节点
    while (p->next != nullptr) p = p->next;
    // 现在p就是链表的最后一个节点
    // 在p后面插入新节点
    p->next = new ListNode<int>(6);
    printLinkedList(head);
    // 现在的链表：0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // 3.在第3个节点后面插入一个新节点66
    // 先要找到前驱节点，及第3个节点
    ListNode<int>* p2 = head;
    for (int i = 0; i < 2; i++) p2 = p2->next;
    // 此时p指向第3个节点
    // 组装新节点的后驱指针
    ListNode<int>* newNode2 = new ListNode<int>(66);
    // 插入新节点
    newNode2->next = p2->next;
    p2->next = newNode2;
    printLinkedList(head);
    // 现在的链表：0 -> 1 -> 2 -> 66 -> 3 -> 4 -> 5 -> 6
    // 删
    // 1.删除第4个节点，要操作前驱节点
    ListNode<int>* p3 = head;
    for (int i = 0; i < 2; i++) p3 = p3->next;
    // 此时p指向第3个节点，即要删除节点的前驱节点
    // 把第4个节点从链表中摘除
    p3->next = p3->next->next;
    printLinkedList(head);
    // 2.删除尾节点
    ListNode<int>* p4 = head;
    // 找到倒数第二个节点
    // 把尾节点从链表中删除
    while (p4->next->next != nullptr) p4 = p4->next;
    // 此时p指向倒数第二个节点
    // 把尾节点从链表中摘除
    p4->next = nullptr;
    printLinkedList(head);
    // 3.删除头节点
    head = head->next;
    printLinkedList(head);
    return 0;
}