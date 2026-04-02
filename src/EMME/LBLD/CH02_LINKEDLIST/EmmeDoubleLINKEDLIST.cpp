//
// Created by Geek.Kwok on 2026/4/2.
//
#include<iostream>
#include<vector>
using namespace std;

template<typename E>
class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    DoublyListNode(DoublyListNode* prev, E element, DoublyListNode* next) {
        this->val = element;
        this->prev = prev;
        this->next = next;
    }
};
// 输入一个数组，转换为一条双链表
DoublyListNode<int>* createDoublyLinkedList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    DoublyListNode<int>* head = new DoublyListNode<int>(arr[0]);
    DoublyListNode<int>* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        DoublyListNode<int>* newNode = new DoublyListNode<int>(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}

void printLinkedList(DoublyListNode<int>* head) {
    if (head == nullptr) return;
    for (DoublyListNode<int>* p = head; p != nullptr; p = p->next) cout << p->val << " ";
    cout << endl;
}

int main() {
    // 创建一条双链表
    DoublyListNode<int>* head = createDoublyLinkedList({1, 2, 3, 4, 5});
    DoublyListNode<int>* tail = nullptr;
    // 查与改
    // 从头节点向后遍历双链表
    for (DoublyListNode<int>* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
        tail = p;
    }
    cout << endl;
    // 从尾节点向前遍历双链表
    for (DoublyListNode<int>* p = tail; p != nullptr; p = p->prev) cout << p->val << endl;
    // 增
    // 1.在双链表头部插入新节点0
    DoublyListNode<int>* newHead = new DoublyListNode<int>(0);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;
    // 现在的链表：0 -> 1 -> 2 -> 3 -> 4 -> 5
    // 2.在双链表尾部插入新节点6
    DoublyListNode<int>* newTail = new DoublyListNode<int>(6);
    tail->next = newTail;
    newTail->prev = tail;
    // 更新尾节点引用
    tail = newTail;
    // 现在的链表：0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // 3.想要插入到索引3（第4个节点）
    // 需要操作索引2（第3个节点）的指针
    DoublyListNode<int>* p = head;
    for (int i = 0; i < 2; i++) {
        p = p->next;
    }
    // 组装新节点
    DoublyListNode<int>* newNode = new DoublyListNode<int>(66);
    newNode->next = p->next;
    newNode->prev = p;
    // 插入新节点
    p->next->prev = newNode;
    p->next = newNode;
    // 现在的链表：0 -> 1 -> 2 -> 66 -> 3 -> 4 -> 5 -> 6
    printLinkedList(head);
    return 0;
}