//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
using namespace std;

template<typename E>

class MyDeque {
    // 从队头插入元素，时间复杂度O(1)
    void addFirst(E e);

    // 从队尾插入元素，时间复杂度O(1)
    void addLast(E e);

    // 从队头删除元素，时间复杂度O(1)
    E removeFirst();

    // 从队尾删除元素，时间复杂度O(1)
    E removeLast();

    // 查看队头元素，时间复杂度O(1)
    E peekFirst();

    // 查看队尾元素，时间复杂度O(1)
    E peekLast();
};

int main() {
    return 0;
}