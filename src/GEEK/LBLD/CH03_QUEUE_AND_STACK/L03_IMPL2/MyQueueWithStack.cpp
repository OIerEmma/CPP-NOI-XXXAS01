//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <stack>
using namespace std;

class MyQueueWithStack {
private:
    stack<int> s1, s2;

public:
    MyQueueWithStack() {
        // Constructor initializes two stacks
    }

    // 添加元素到队尾
    void push(int x) {
        s1.push(x);
    }

    // 删除队头元素并返回
    int pop() {
        // 先调用 peek 保证 s2 非空
        peek();
        int topElement = s2.top();
        s2.pop();
        return topElement;
    }

    // 返回队头元素
    int peek() {
        if (s2.empty()) {
            // 把 s1 元素全部压入 s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // 判断队列是否为空
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {

    return 0;
}