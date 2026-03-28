//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <deque>
#include "../../CH01_ARRAY/L01_CYCLEARRAY/CycleArray.cpp"
template <typename E>

class MyArrayQueue {
private:
    CycleArray<E> arr;

public:
    MyArrayQueue() {
        arr = CycleArray<E>();
    }

    void push(E t) {
        arr.addLast(t);
    }

    E pop() {
        return arr.removeFirst();
    }

    E peek() {
        return arr.getFirst();
    }

    int size() {
        return arr.size();
    }
};
