//
// Created by Geek.Kwok on 2026/3/28.
//
#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    vector<int> arr;
    int start, end, count;

public:
    MyCircularQueue(int k) {
        arr = vector<int>(k);
        start = end = count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        arr[end] = value;
        end = (end + 1) % arr.size();
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        arr[start] = 0;
        start = (start + 1) % arr.size();
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[(end - 1 + arr.size()) % arr.size()];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == arr.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */