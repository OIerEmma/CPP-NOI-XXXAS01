//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <queue>
#include <list>
using namespace std;

// 普通队列的API
class MyQueue {
public:
    // enqueue 操作，在队尾加入元素 n
    void push(int n);
    // dequeue 操作，删除队头元素
    void pop();
};

// 单调队列的API
class MyMonotonicQueue {
private:
    // 双链表，支持快速在头部和尾部增删元素
    // 维护其中的元素使得自尾部到头部单调递增
    list<int> maxq;

public:
    // 在队尾添加元素 n，维护 maxq 的单调性质
    void push(const int n) {
        // 将前面小于自己的元素都删除
        while (!maxq.empty() && maxq.back() < n) {
            maxq.pop_back();
        }
        maxq.push_back(n);
    }

    // 队头元素如果是n，删除它
    void pop(const int n) {
        if (n == maxq.front()) {
            maxq.pop_front();
        }
    }

    // 返回当前队列中的最大值
    int max() const {
        // 队头元素肯定是最大的
        return maxq.front();
    }

    // 返回当前队列中的最小值
    int min() const {
        // 队尾元素肯定是最小的
        return maxq.back();
    }
};

int main() {

    return 0;
}