//
// Created by Geek.Kwok on 2026/3/26.
//
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename E>

class MyLinkedList {
private:
    // 节点结构
    struct Node {
        E val;
        Node* next;

        Node(E value) : val(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size_;

public:
    MyLinkedList() {
        head = new Node(E());
        tail = head;
        size_ = 0;
    }

    ~MyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // ****** 增 ******
    void addFirst(E e) {
        Node* newNode = new Node(e);
        newNode->next = head->next;
        head->next = newNode;
        if (size_ == 0) {
            tail = newNode;
        }
        size_++;
    }

    void addLast(E e) {
        Node* newNode = new Node(e);
        tail->next = newNode;
        tail = newNode;
        size_++;
    }

    void add(int index, E element) {
        checkPositionIndex(index);
        if (index == size_) {
            addLast(element);
            return;
        }

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        Node* newNode = new Node(element);
        newNode->next = prev->next;
        prev->next = newNode;
        size_++;
    }

    // ****** 删 ******
    E removeFirst() {
        if (isEmpty()) {
            throw out_of_range("No elements to remove");
        }
        Node* first = head->next;
        head->next = first->next;
        if (size_ == 1) {
            tail = head;
        }
        size_--;
        E val = first->val;
        delete first;
        return val;
    }

    E removeLast() {
        if (isEmpty()) {
            throw out_of_range("No elements to remove");
        }
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        E val = tail->val;
        delete tail;
        prev->next = nullptr;
        tail = prev;
        size_--;
        return val;
    }

    E remove(int index) {
        checkElementIndex(index);

        Node* prev = head;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }

        Node* nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
        // 删除的是最后一个元素
        if (index == size_ - 1) {
            tail = prev;
        }
        size_--;
        E val = nodeToRemove->val;
        delete nodeToRemove;
        return val;
    }

    // ****** 查 ******
    E getFirst() {
        if (isEmpty()) {
            throw out_of_range("No elements in the list");
        }
        return head->next->val;
    }

    E getLast() {
        if (isEmpty()) {
            throw out_of_range("No elements in the list");
        }
        return tail->val;
    }

    E get(int index) {
        checkElementIndex(index);
        Node* p = getNode(index);
        return p->val;
    }

    // ****** 改 ******
    E set(int index, E element) {
        checkElementIndex(index);
        Node* p = getNode(index);

        E oldVal = p->val;
        p->val = element;

        return oldVal;
    }

    // ****** 其他工具函数 ******
    bool size() {
        return size_;
    }

    bool isEmpty() {
        return size_ == 0;
    }

    void display() {
        cout << "size = " << size_ << endl;
        for (Node* p = head->next; p != nullptr; p = p->next) {
            cout << p->val << " <-> ";
        }
        cout << "nullptr" << endl;
        cout << endl;
    }

private:
    // 返回 index 对应的 Node
    // 注意：请保证传入的 index 是合法的
    Node* getNode(int index) {
        Node* p = head->next;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }

    bool isPositionIndex(int index) {
        return index >= 0 && index <= size_;
    }

    void checkPositionIndex(int index) {
        if (!isPositionIndex(index)) {
            throw out_of_range("Index: " + to_string(index) + ", Size_: " + to_string(size_));
        }
    }

    bool isElementIndex(int index) {
        return index >= 0 && index < size_;
    }

    void checkElementIndex(int index) {
        if (!isElementIndex(index)) {
            throw out_of_range("Index: " + to_string(index) + ", Size_: " + to_string(size_));
        }
    }
};

int main() {
    MyLinkedList<int> list;
    list.addFirst(1);
    list.addFirst(2);
    list.addLast(3);
    list.addLast(4);
    list.add(2, 5);

    list.display();

    cout << list.removeFirst() << endl; // 2
    cout << list.removeLast() << endl; // 4
    cout << list.remove(1) << endl; // 5

    cout << list.getFirst() << endl; // 1
    cout << list.getLast() << endl; // 3
    cout << list.get(1) << endl; // 3

    return 0;
}