//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class MyCircularDeque {
    vector<int> arr;
    int start, end, count;

public:
    MyCircularDeque(int k) {
        arr = vector<int>(k);
        start = end = count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        arr[end] = value;
        end = (end + 1) % arr.size();
        count++;
        return true;
    }

    bool deleteFront() {
        if(isEmpty()) return false;
        start = (start + 1) % arr.size();
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        end = (end - 1 + arr.size()) % arr.size();
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    int getRear() {
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */