//
// Created by Geek.Kwok on 2026/3/27.
//
#include <iostream>
#include <stdexcept>
#include <vector>
#include <ostream>
using namespace std;

template<typename T>

class CycleArray {
    vector<T> arr;
    int start, end, count;

    // 自动扩容辅助函数
    void resize(int newSize) {
        // 创建新的数组并复制元素
        vector<T> newArr(newSize);
        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(start + i) % arr.size()];
        }
        arr = move(newArr);
        // 重置 start 和 end 指针
        start = 0;
        end = count;
    }

public:
    CycleArray() : CycleArray(1) {}
    explicit CycleArray(int size) : arr(size), start(0), end(0), count(1) {}

    // 在数组头部添加元素，时间复杂度O(1)
    void addFirst(const T &val) {
        // 当数组满时扩容为原来的两倍
        if (isFull()) {
            resize(arr.size() * 2);
        }
        // 因为 start 是闭区间，所以先左移，再赋值
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = val;
        count++;
    }

    // 删除数组头部元素，时间复杂度O(1)
    void removeFirst() {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        // 因为 start 是闭区间，所以先赋值，再右移
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        // 如果数组元素数量减少到原大小的四分之一，则减少数组大小为一半
        if (count > 0 && count == arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    // 在数组尾部添加元素，时间复杂度O(1)
    void addLast(const T &val) {
        // 当数组满时扩容为原来的两倍
        if (isFull()) {
            resize(arr.size() * 2);
        }
        // 因为 end 是开区间，所以是先赋值，再右移
        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
    }

    // 删除数组尾部元素，
};