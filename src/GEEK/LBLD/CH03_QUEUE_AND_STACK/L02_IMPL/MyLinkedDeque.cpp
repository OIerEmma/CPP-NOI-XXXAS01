//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <list>
using namespace std;

template <typename E>

class MyLinkedDeque {
private:
    list<E> list_;

public:
    // 从队头插入元素，时间复杂度O(1)
    void addFirst(const E& e) {
        list_.push_front(e);
    }

    // 从队尾插入元素，时间复杂度O(1)
    void addLast(const E& e) {
        list_.push_back(e);
    }

    // 从队头删除元素，时间复杂度O(1)
    E removeFirst() {
        E firstElement = list_.front();
        list_.pop_front();
        return firstElement;
    }

    // 从队尾删除元素，时间复杂度O(1)
    E removeLast() {
        E lastElement = list_.back();
        list_.pop_back();
        return lastElement;
    }

    // 查看队头元素，时间复杂度O(1)
    E peekFirst() {
        return list_.front();
    }

    // 查看队尾元素，时间复杂度O(1)
    E peekLast() {
        return list_.back();
    }
};

int main() {
    MyLinkedDeque<int> deque;
    deque.addFirst(1);
    deque.addFirst(2);
    deque.addLast(3);
    deque.addLast(4);

    cout << deque.removeFirst() << endl; // 2
    cout << deque.removeLast() << endl; // 4
    cout << deque.peekFirst() << endl; // 1
    cout << deque.peekLast() << endl; // 3

    return 0;
}