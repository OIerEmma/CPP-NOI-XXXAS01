//
// Created by Amy on 2026/4/5.
//
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

template<typename E>

class AmyMyDoublyList {
    struct Node {
        E val;
        Node* next;
        Node* prev;

        Node(E value): val(value),next(nullptr),prev(nullptr){}
    };

    Node* head;
    Node* tail;
    int size;
public:
    AmyMyDoublyList() {
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    ~AmyMyDoublyList() {
        while(size > 0) {
            removeFirst();
        }
        delete head;
        delete tail;
    }

    void addLast(E e) {
        Node* x = new Node(e);
        Node* temp = tail->prev;

        temp->next = x;
        x->prev = temp;

        x->next = tail;
        tail->prev = x;
        size++;
    }

    void addFirst(E e) {
        Node* x = new Node(e);
        Node* temp = head->next;
        temp->prev = x;
        x->next = temp;

        head->next = x;
        x->prev = head;
        size++;
    }

    void add(int index,E element) {
        checkPositionIndex(index);
        if(index == size) {
            addLast(element);
            return;
        }

        Node* p = getNode(index);
        Node* temp = p->prev;

        Node* x = new Node(element);

        p->prev = x;
        temp->next = x;

        x->prev = temp;
        x->next = p;

        size++;
    }

    E removeFirst () {
        if(size<1) {
            throw out_of_range("No elements to remove");
        }
        Node* x = head->next;
        Node* temp = x->next;
        head->next = temp;
        temp->prev = head;
        E val = x->val;
        delete x;

        size--;
        return val;
    }

    E removeLast() {
        if(size < 1) {
            throw out_of_range("No elements to remove");
        }
        Node* x = tail->prev;
        Node* temp = tail->prev->prev;

        tail->prev = temp;
        temp->next = tail;

        E val = x->val;
        x->prev = nullptr;
        x->next = nullptr;
        delete x;

        size--;
        return val;
    }

    E remove(int index) {
        checkElementIndex(index);
        Node* x = getNode(index);
        Node* prev = x->prev;
        Node* next = x->next;
        prev->next = next;
        next->prev = prev;

        E val = x->val;
        x->prev = nullptr;
        x->next = nullptr;
        delete x;

        size--;
        return val;
    }

    E get(int index) {
        checkElementIndex(index);
        Node* p = getNode(index);

        return p->val;
    }

    E getFirst() {
        if(size < 1) {
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

    E set(int index, E val) {
        checkElementIndex(index);
        Node* p = getNode(index);

        E oldVal = p->val;
        p->val = val;

        return oldVal;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void display() {
        cout << "size = "<< size << endl;
        for(Node* p = head->next; p != tail; p = p->next) {
            cout << p->val << " <-> ";
        }
        cout << "nullptr" << endl;
        cout << endl;
    }
private:
    Node* getNode(int index) {
        checkElementIndex(index);
        Node* p = head->next;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        return p;
    }

    bool isElementIndex(int index)const {
        return index >= 0 && index < size;
    }
    void checkElementIndex(int index)const {
        if(!isElementIndex(index)) {
            throw out_of_range("Index: " + to_string(index) + ", size: " + to_string(size));
        }
    }
    bool isPositionIndex(int index)const {
        return index >= 0 && index <= size;
    }
    void checkPositionIndex(int index)const {
        if(!isPositionIndex(index)) {
            throw out_of_range("Index: " + to_string(index) + ", size: " + to_string(size));
        }
    }
};

int main() {
    AmyMyDoublyList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(0);
    list.add(2, 100);

    list.display();

    return 0;
}   