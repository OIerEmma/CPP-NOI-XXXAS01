//
// Created by Geek.Kwok on 2026/3/24.
//
#include<iostream>
#include<stdexcept>
#include<vector>
using namespace std;

template<typename E>
class EmmeArrayList{
private:
    E*data; // 真正存储数据的底层数组
    int size; // 记录当前元素个数
    int cap; // 最大元素容量
    static const int INIT_CAP = 1; // 默认初始容量

public:
    EmmeArrayList() {
        this->data = new E[INIT_CAP];
        this->size = 0;
        this->cap = INIT_CAP;
    }
    EmmeArrayList(int initCapacity) {
        this->data = new E[initCapacity];
        this->size = 0;
        this->cap = initCapacity;
    }
    // 增
    void addLast(E e) {
        // 看data数组容量够不够
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
        // 看data数组容量够不够
        if (size == cap) {
            // 扩容
            resize(2 * cap);
        }
        // 搬移数据
        // 给新元素腾出位置
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        // 插入一个新元素
        data[index] = e;
        size++;
    }
    void addFirst(E e) {
        add(0, e);
    }
    // 删
    E removeLast() {
        // 检查数组是否为空
        if (size == 0) {
            throw out_of_range("NoSuchElementException");
        }
        // 可以缩容节约空间
        if (size == cap / 4) {
            resize(cap / 2);
        }
        E deleteVal = data[size - 1];
        // 删除最后一个元素
        // 必须给最后一个元素置为null，否则会内存泄漏
        data[size - 1] = E();
        size--;
        return deleteVal;
    }
    E remove(int index) {
        // 检查索引越界
        checkElementIndex(index);
        // 可以缩容节约空间
        if (size == cap / 4) {
            resize(cap / 2);
        }
        E deleteVal = data[index];
        // 搬移数据 data[index + 1..] -> data[index..]
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        data[size - 1] = E();
        size--;
        return deleteVal;
    }
    E removeFirst() {
        remove(0);
    }
    // 查
    E get(int index) {
        // 检查索引越界
        checkElementIndex(index);
        return data[index];
    }
    // 改
    E set(int index, E element) {
        // 检查索引越界
        checkElementIndex(index);
        // 修改数据
        E oldVal = data[index];
        data[index] = element;
        return oldVal;
    }
    // 工具方法
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void display() {
        cout << "size = " << size << " cap = " << cap << endl;
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    ~EmmeArrayList(){
        delete []data;
    }
    // 将data的容量改为 newCap
    void resize(int newCap) {
        E* temp = new E[newCap]; // 申请新空间
        // 数据迁移
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete []data; // 释放原数组内存
        data = temp;
        cap = newCap;
    }
    bool isPositionIndex(int index) {
        return index >= 0 && index <= size;
    }
    void checkPositionIndex(int index) {
        if (!isPositionIndex(index)) {
            throw out_of_range("index out of bounds");
        }
    }
    bool isElementIndex(int index) {
        return index >= 0 && index <= size;
    }
    void checkElementIndex(int index) {
        if (!isElementIndex(index)) {
            throw out_of_range("index out of bounds");
        }
    }
};

int main() {
    EmmeArrayList<int> arr(3);
    for (int i = 1; i <= 5; i++) {
        arr.addLast(i);
    }
    arr.remove(3);
    arr.add(1, 9);
    arr.removeLast();
    arr.addFirst(100);
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr.get(i) << endl;
    }
    return 0;
}