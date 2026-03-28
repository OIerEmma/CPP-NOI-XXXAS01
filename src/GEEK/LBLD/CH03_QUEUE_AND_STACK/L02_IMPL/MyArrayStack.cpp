//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <vector>
using namespace std;

template <typename E>

class MyArrayStack {
private:
    vector<E> arr;

public:
    // 向栈顶加入元素，时间复杂度O(1)
    void push(const E& e) {
        arr.push_back(e);
    }

    // 从栈顶弹出元素，时间复杂度O(1)
    E pop() {
        E topElement = arr.back();
        arr.pop_back();
        return topElement;
    }

    // 查看栈顶元素，时间复杂度O(1)
    E peek() const {
        return arr.back();
    }

    // 返回栈中的元素个数，时间复杂度O(1)
    int size() const {
        return arr.size();
    }
};

int main() {
    return 0;
}