//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
using namespace std;

template <typename E>

// 队列的基本 API
class MyQueue {
public:
    // 向队尾插入元素，时间复杂度O(1)
    void push(const E& e);

    // 从队头删除元素，时间复杂度O(1)
    E pop();

    // 查看队头元素，时间复杂度O(1)
    E peek() const;

    // 返回队列中的元素个数，时间复杂度O(1)
    int size() const;
};

int main() {

    return 0;
}