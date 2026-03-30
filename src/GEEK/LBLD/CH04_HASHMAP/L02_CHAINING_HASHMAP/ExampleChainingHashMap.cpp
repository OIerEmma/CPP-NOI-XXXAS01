//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 用拉链法解决哈希冲突的简化实现
 */
class ExampleChainingHashMap {
    // 链表节点，存储 Key-Value 对
    // 注意这里必须同时存储 Key 和 Value
    // 因为要通过 Key 找到对应的 Value
    struct KVNode {
        int key, value;
        // 为了简化我这里直接用标准库的 LinkedList 链表
        // 所以这里就不添加 next 指针了
        // 你当然可以给 KVNode 添加 next 指针，自己实现链表操作
        KVNode(int key, int value) : key(key), value(value) {}
    };

    // 底层 table 数组中的每个元素是一个链表
    vector<list<KVNode>> table;

public:
    ExampleChainingHashMap(int capacity) : table(capacity) {}

    int hash(int key) {
        return key % table.size();
    }

    // 查
    int get(int key) {
        int index = hash(key);
        if (table[index].empty()) {
            // 链表为空，说明 key 不存在
            return -1;
        }
        for (const auto& node: table[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        // 链表中没有目标 key
        return -1;
    }

    // 增/改
    void put(int key, int value) {
        int index = hash(key);
        if (table[index].empty()) {
            // 链表为空，新建一个链表，插入Key-Value
            table[index].push_back(KVNode(key, value));
            return;
        }
        // 链表不为空，要遍历一遍看看 key 是否已经存在
        // 如果存在则更新 value 如果不存在则插入新节点
        for (auto& node: table[index]) {
            if (node.key == key) {
                // key 已经存在则更新 value
                node.value = value;
                return;
            }
        }
        // 链表中没有目标 key 则添加新节点
        // 这里使用 push_back 添加到链表尾部
        // 因为 C++ list 的底层实现是双链表，头尾操作都是O(1)
        table[index].push_back(KVNode(key, value));
    }

    // 删
    void remove(int key) {
        auto& list = table[hash(key)];
        if (list.empty()) return;
        // 如果 key 存在则删除
        // 这个 remove_if 方法是 C++ list 的方法，可以删除满足条件的元素，时间复杂度O(N)
        list.remove_if([key](const KVNode& node) { return node.key == key; });
    }
};

int main() {

    return 0;
}