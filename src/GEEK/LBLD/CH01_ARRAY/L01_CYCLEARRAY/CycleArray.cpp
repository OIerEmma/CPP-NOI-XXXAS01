//
// Created by Geek.Kwok on 2026/3/27.
//
#include <iostream>
#include <stdexcept>
#include <vector>
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
    explicit CycleArray(int size) : arr(size), start(0), end(0), count(0) {}

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
        // 缩容：如果数组元素数量减少到原大小的四分之一，则减少数组大小为一半
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

    // 删除数组尾部元素，时间复杂度O(1)
    void removeLast() {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        // 因为 end 是开区间，所以先左移，再赋值
        end = (end - 1 + arr.size()) % arr.size();
        arr[end] = T();
        count--;
        // 缩容：如果数组元素数量减少到原来大小的四分之一，则减少数组大小为一半
        if (count > 0 && count == arr.size() / 4) {
            resize(arr.size() / 2);
        }
    }

    // 获取数组头部元素，时间复杂度O(1)
    T getFirst() const {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        return arr[start];
    }

    // 获取数组尾部元素，时间复杂度O(1)
    T getLast() const {
        if (isEmpty()) {
            throw runtime_error("Array is empty");
        }
        // end 是开区间，指向的是下一个元素的位置，所以要减 1
        return arr[(end - 1 + arr.size()) % arr.size()];
    }

    bool isFull() const {
        return count == arr.size();
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) return;
        for (int i = 0; i < count; i++) {
            cout << arr[(start + i) % arr.size()] << " ";
        }
        cout << endl;
    }
};

int main() {
    CycleArray<int> carr;
    carr.addLast(1);
    carr.addLast(2);
    carr.addFirst(3);
    carr.addFirst(4);
    carr.display();

    carr.removeFirst();
    carr.display();
    carr.removeLast();
    carr.display();

    return 0;
}