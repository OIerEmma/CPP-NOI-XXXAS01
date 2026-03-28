//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <queue>
using namespace std;

class MyStackWithQueue {
private:
    queue<int> q;
    int top_element = 0;

public:
    // 添加元素到栈顶
    void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q.push(x);
        top_element = x;
    }

    // 删除栈顶元素并返回
    int pop() {
        int size = q.size();
        // 留下队尾 2 个元素
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size--;
        }
        // 记录新的队尾元素
        top_element = q.front();
        q.push(q.front());
        q.pop();
        // 之前的队尾元素已经到了队头
        int res = q.front();
        q.pop();
        return res;
    }

    // 返回栈顶元素
    int top() {
        return top_element;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {

    return 0;
}