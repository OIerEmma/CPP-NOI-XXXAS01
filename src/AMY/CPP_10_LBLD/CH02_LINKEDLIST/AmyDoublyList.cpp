//
// Created by Amy on 2026/4/2.
//
#include<iostream>
#include<vector>
using namespace std;

template<typename E>
class DoublyListNode {
public:
    E val;
    DoublyListNode* next;
    DoublyListNode* prev;
    explicit DoublyListNode(E x) : val(x), next(nullptr), prev(nullptr) {}
    explicit DoublyListNode(E element, DoublyListNode* prev, DoublyListNode* next) {
        this->val = element;
        this->next = next;
        this->prev = prev;
    }
};

//输入一个数组，转换为一条双链表
DoublyListNode<int>* createDoublyLinkedList(const vector<int>& arr) {
    if(arr.empty()) {
        return nullptr;
    }
    DoublyListNode<int>* head = new DoublyListNode<int>(arr[0]);
    DoublyListNode<int>* cur = head;
    for(int i = 1; i < arr.size(); i++) {
        DoublyListNode<int>* newNode= new DoublyListNode<int>(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}

void printLinkedList(DoublyListNode<int>* head) {
    if (head == nullptr) { return; }
    //遍历单链表
    for(DoublyListNode<int>* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
}

int main() {
    //创建一条双链表
    DoublyListNode<int>* head = createDoublyLinkedList({1, 2, 3, 4, 5});
    DoublyListNode<int>* tail = nullptr;

    for (DoublyListNode<int>* p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
        tail = p;
    }
    cout << endl;
    for (DoublyListNode<int>* p = tail; p != nullptr; p = p->prev) {
        cout << p->val << " ";
    }
    cout << endl;

    DoublyListNode<int>* newHead = new DoublyListNode<int>(0);
    newHead->next = head;
    head->prev = newHead;
    head = newHead;

    DoublyListNode<int>* newtail = new DoublyListNode<int>(6);
    tail->next = newtail;
    newtail->prev = tail;
    tail = newtail;

    DoublyListNode<int>* p = head;
    for(int i = 0; i < 2; i++) {
        p = p->next;
    }
    DoublyListNode<int>* newNode = new DoublyListNode<int>(66);
    newNode->next = p->next;
    newNode->prev = p;

    p->next->prev = newNode;
    p->next = newNode;
    printLinkedList(head);

    DoublyListNode<int>* p2 = head;
    for (int i = 0; i < 2; ++i) {
        p2 = p2->next;
    }

    DoublyListNode<int>* toDelete = p->next;

    p->next = toDelete->next;
    toDelete->next->prev = p;

    toDelete->next = nullptr;
    toDelete->prev = nullptr;

    DoublyListNode<int>* toDelete2 = head;
    head = head->next;
    head->prev = nullptr;

    toDelete2->next = nullptr;

    DoublyListNode<int>* p3 = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->prev->next = nullptr;
    p->prev = nullptr;
    return 0;
}
