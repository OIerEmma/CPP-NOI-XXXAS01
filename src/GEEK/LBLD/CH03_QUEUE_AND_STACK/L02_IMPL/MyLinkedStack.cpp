//
// Created by Geek.Kwok on 2026/3/29.
//
/**
 * 用链表作为底层数据结构实现栈
 */
#include <iostream>
#include <list>
using namespace std;

template <typename E>

class MyLinkedStack {
private:
    list<E> list_;

public:
    // 向栈顶加入元素，时间复杂度O(1)
    void push(const E& e) {
        list_.push_back(e);
    }

    // 从栈顶弹出元素，时间复杂度O(1)
    E pop() {
        E value = list_.back();
        list_.pop_back();
        return value;
    }

    // 查看栈顶元素，时间复杂度O(1)
    E peek() const {
        return list_.back();
    }

    // 返回栈中的元素个数，时间复杂度O(1)
    int size() const {
        return list_.size();
    }
};

int main() {
    MyLinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    while (stack.size() > 0) {
        cout << stack.pop() << endl;
    }
    return 0;
}