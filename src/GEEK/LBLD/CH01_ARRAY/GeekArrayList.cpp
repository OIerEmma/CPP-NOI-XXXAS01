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

    // 增 //
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

    // 删 //
    E removeLast() {
        if (size == 0) {
        throw out_of_range("NoSuchElementException");
        }
        // 可以缩容，节约控件
        if (size == cap / 4) {
        resize(cap / 2);
        }
        E deletedVal = data[size - 1];
        // 删除最后一个元素
        // 必须给最后一个元素置为null，否则会内存泄漏
        data[size - 1] = E();
        size--;

        return deletedVal;
    }

    E remove(int index) {
        // 检查索引越界
        checkElementIndex(index);
        // 可以缩容，节约控件
        if (size == cap / 4) {
            resize(cap / 2);
        }
        E deletedVal = data[index];
        // 搬移数据
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        data[size - 1] = E();
        size--;

        return deletedVal;
    }

    E removeFirst() {
      return remove(0);
    }

    // 查 //
    E get(int index) {
      // 检查索引越界
      checkElementIndex(index);

      return data[index];
    }

    // 改 //
    E set(int index, E element) {
      // 检查索引越界
      checkElementIndex(index);
      // 修改数据
      E oldVal = data[index];
      data[index] = element;
      return oldVal;
    }

    // 工具类方法
    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
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

    bool isElementIndex(int index) {
      return index >= 0 && index < size;
    }

    // 检查 index 索引位置是否可以存在元素
    bool checkElementIndex(int index) {
      if (!isElementIndex(index)) {
        throw out_of_range("index out of bounds");
      }
    }

    ~GeekArrayList() {
      delete []data;
    }
};

int main() {
  // 初始容量设置为3
  GeekArrayList<int> arr(3);

  // 添加5个元素
  for (int i = 0; i < 5; i++) {
    arr.addLast(i);
  }

  arr.remove(3);
  arr.add(1, 9);
  arr.addFirst(100);
  int val = arr.removeLast();

  // 100 1 9 2 3
  for (int i = 0; i < arr.getSize(); i++) {
    cout << arr.get(i) << " ";
  }
  cout << endl;

  return 0;
}