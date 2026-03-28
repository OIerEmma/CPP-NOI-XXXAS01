//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
using namespace std;

template <typename E>

// 栈的基本 API
class MyStack {
public:
    // 向栈顶插入元素，时间复杂度O(1)
    void push(const E& e);

    // 从栈顶删除元素，时间复杂度O(1)
    E pop();

    // 查看栈顶元素，时间复杂度O(1)
    E peek() const;

    // 返回栈中的元素个数，时间复杂度O(1)
    int size() const;
};

int main() {

    return 0;
}