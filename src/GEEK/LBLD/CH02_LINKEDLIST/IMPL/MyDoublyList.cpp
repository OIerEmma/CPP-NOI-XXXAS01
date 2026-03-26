//
// Created by Geek.Kwok on 2026/3/26.
//
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template<typename E>

class MyDoublyList {
    // 虚拟头尾节点
    struct Node {
        E val;
        Node* next;
        Node* prev;

        Node(E value) : val(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // 构造函数初始化虚拟头尾节点
    MyDoublyList() {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~MyDoublyList() {
        while (size > 0) {
            removeFirst();
        }
        delete head;
        delete tail;
    }

    // ****** 增 ******
    void addLast(E e) {
        Node* x = new Node(e);
        Node* temp = tail->prev;
        // temp <--> tail
        temp->next = x;
        x->prev = temp;

        x->next = tail;
        tail->prev = x;
        // temp <--> x <--> tail
        size++;
    }

    void addFirst(E e) {
        Node* x = new Node(e);
        Node* temp = head->next;
        // head <--> temp
        temp->prev = x;
        x->next = temp;

        head->next = x;
        x->prev = head;
        // head <--> x <--> temp
        size++;
    }

    void add(int index, E element) {
        checkPositionIndex(index);
        if (index == size) {
            addLast(element);
            return;
        }
        // 找到 index 对应的 Node
        Node* p = getNode(index);
        Node* temp = p->prev;
        // temp <--> p
        // 新建要插入的 Node
        Node* x = new Node(element);
        p->prev = x;
        temp->next = x;

        x->prev = temp;
        x->next = p;
        // temp <--> x <--> p
        size++;
    }

    // ****** 删 ******
    E removeFirst() {
        if (size < 1) {
            throw out_of_range("No elements to remove");
        }
        // 虚拟节点head的存在是我们不用考虑空指针的问题
        Node* x = head->next;
        Node* temp = x->next;
        // head <--> x <--> temp
        head->next = temp;
        temp->prev = head;

        E val = x->val;
        x->prev = x->next = nullptr;
        delete x;
        // head <--> temp

        size--;
        return val;
    }

    E removeLast() {
        if (size < 1) {
            throw out_of_range("No elements to remove");
        }
        // 虚拟节点tail的存在是我们不用考虑空指针的问题
        Node* x = tail->prev;
        Node* temp = x->prev;
        // temp <--> x <--> tail
        tail->prev = temp;
        temp->next = tail;

        E val = x->val;
        x->prev = x->next = nullptr;
        delete x;
        // temp <--> tail

        size--;
        return val;
    }

    E remove(int index) {
        checkElementIndex(index);
        // 找到 index 对应的 Node
        Node* x = getNode(index);
        Node* prev = x->prev;
        Node* next = x->next;
        // prev <--> x <--> next
        prev->next = next;
        next->prev = prev;

        E val = x->val;
        x->prev = x->next = nullptr;
        delete x;
        // prev <--> next

        size--;
        return val;
    }

    // ****** 查 ******
    E get(int index) {
        checkElementIndex(index);
        // 找到 index 对应的 Node
        Node* p = getNode(index);

        return p->val;
    }

    E getFirst() {
        if (size < 1) {
            throw out_of_range("No elements in the list");
        }

        return head->next->val;
    }

    E getLast() {
        if (size < 1) {
            throw out_of_range("No elements in the list");
        }

        return tail->prev->val;
    }

    // ****** 改 ******
    E set(int index, E val) {
        checkElementIndex(index);
        // 找到 index 对应的 Node
        Node* p = getNode(index);

        E oldVal = p->val;
        p->val = val;

        return oldVal;
    }

    // ****** 其他工具函数 ******
    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() {
        cout << "size = " << size << endl;
        for (Node* p = head->next; p != tail; p = p->next) {
            cout << p->val << " <-> ";
        }
        cout << "nullptr" << endl;
        cout << endl;
    }

private:
    Node* getNode(int index) {
        checkElementIndex(index);
        Node* p = head->next;
        // TODO: 可以优化，通过 index 判断从 head 还是 tail 开始遍历
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }

    bool isPositionIndex(int index) {
        return index >= 0 && index <= size;
    }

    void checkPositionIndex(int index) {
        if (!isPositionIndex(index)) {
            throw out_of_range("Index: " + to_string(index) + ", Size: " + to_string(size));
        }
    }

    bool isElementIndex(int index) const {
        return index >= 0 && index < size;
    }

    void checkElementIndex(int index) {
        if (!isElementIndex(index)) {
            throw out_of_range("Index: " + to_string(index) + ", Size: " + to_string(size));
        }
    }
};

int main() {
    MyDoublyList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(0);
    list.add(2, 100);

    list.display();
    // size = 5
    // 0 <--> 1 <--> 100 <--> 2 <--> 3 <--> null

    return 0;
}