//
// Created by Geek.Kwok on 2026/3/24.
//
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

template<typename E>

class GeekArrayList {
private:
    // 真正存储数据的底层数组
    E* data;
    // 记录当前元素个数
    int size;
    // 最大元素容量
    int cap;
    // 默认初始容量
    static const int INIT_CAP = 1;

public:
    GeekArrayList() {
        this->data = new E[INIT_CAP];
        this->size = 0;
        this->cap = INIT_CAP;
    }
    GeekArrayList(int initCapacity) {
        this->data = new E[initCapacity];
        this->size = 0;
        this->cap = initCapacity;
    }

    // 增
    void addLast(E e) {
        // 看 data 数组容量够不够
        if (size == cap) {
            // 扩容
            resize(2 * cap);
        }

        // 在尾部插入元素
        data[size] = e;
        size++;
    }

    void add(int index, E e) {
        // 检查索引越界
        checkPositionIndex(index);
        // 看 data 数组容量够不够
        if (size == cap) {
            // 扩容
            resize(2 * cap);
        }
        // 搬移数据
        // 给新元素腾出位置
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }

        // 插入新元素
        data[index] = e;
        size++;
    }

    void addFirst(E e) {
        add(0, e);
    }

    // 将 data 的容量改为 newCap
    void resize(int newCap) {
        // 申请新空间
        E* temp = new E[newCap];
        // 数据迁移
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        // 释放原数组内存
        delete []data;

        data = temp;
        cap = newCap;
    }

    bool isPositionIndex(int index) {
        return index >= 0 && index <= size;
    }

    // 检查 index 索引位置是否可以添加元素
    bool checkPositionIndex(int index) {
        if (!isPositionIndex(index)) {
            throw out_of_range("index out of bounds");
        }
    }
};