//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
using namespace std;

template<typename K, typename V>

class MyChainingHashMap {
    // 拉链法使用的单链表节点，存储 Key-Value 对
    struct KVNode {
        K key;
        V value;

        KVNode(K key, V val) : key(key), value(move(val)) {}
    };

    // 哈希表的底层数组，每个数组元素是一个链表，链表中每个节点是 KVNode 存储键值对
    vector<list<KVNode>> table;
    // 哈希表中存入的键值对个数
    int size_;
    // 底层数组的初始容量
    static constexpr int INIT_CAP = 4;

    // 哈希函数，将键映射到 table 的索引
    int hash(K key) {
        return ( std::hash<K>{}(key) & 0x7fffffff ) % table.size();
    }

    void resize(int newCap) {
        // 构造一个新的 HashMap
        // 避免 newCap 为 0 造成求模运算产生除以 0 的异常
        newCap = max(newCap, 1);
        MyChainingHashMap<K, V> newMap(newCap);
        // 穷举当前 HashMap 中的所有键值对
        for (auto& list: table) {
            for (auto& node: list) {
                // 将键值对转移到新的 HashMap 中
                newMap.put(node.key, node.value);
            }
        }
        // 将当前 HashMap 的底层 table 换掉
        this->table = newMap.table;
    }

public:
    MyChainingHashMap() : MyChainingHashMap(INIT_CAP) {}

    explicit MyChainingHashMap(int initCapacity) {
        size_ = 0;
        // 保证底层数组的容量至少为1，因为hash函数中有求余运算，避免出现除以0的情况
        initCapacity = max(initCapacity, 1);
        table.resize(initCapacity);
    }

    // ****** 增/改 ******
    // 添加 Key-Value 键值对
    // 如果键 Key 已存在，则将值修改为 val
    void put(K key, V val) {
        auto& list = table[hash(key)];
        // 如果 key 之前存在则修改对应的val
        for (auto& node: list) {
            if (node.key == key) {
                node.value = val;
                return;
            }
        }
        // 如果 key 之前不存在，则插入，size增加
        list.emplace_back(key, val);
        size_++;
        // 如果元素数量超过了负载因子则进行扩容
        if (size_ >= table.size() * 0.75) {
            resize(table.size() * 2);
        }
    }

    // ****** 删 ******
    void remove(K key) {
        auto& list = table[hash(key)];
        // 如果 key 存在，则删除，size 减少
        for (auto it = list.begin(); it != list.end(); it++) {
            if (it->key == key) {
                list.erase(it);
                size_--;
                // 当负载因子小于 0.125 时缩容
                if (size_ < table.size() / 8) {
                    resize(table.size() / 4);
                }
                return;
            }
        }
    }

    // ****** 查 ******
    // 返回 key 对应的 val，如果 key 不存在则返回 nullptr
    V get(K key) {
        const auto& list = table[hash(key)];
        for (const auto& node: list) {
            if (node.key == key) {
                return node.value;
            }
        }
        return nullptr;
    }

    // 返回所有 key
    list<K> keys() {
        list<K> keys;
        for (const auto& list: table) {
            for (const auto& node: list) {
                keys.push_back(node.key);
            }
        }
        return keys;
    }

    // ****** 其他工具函数 ******
    int size() const {
        return size_;
    }
};

int main() {
    MyChainingHashMap<int, shared_ptr<int>> map;
    map.put(1, make_shared<int>(1));
    map.put(2, make_shared<int>(2));
    map.put(3, make_shared<int>(3));
    cout << *map.get(1) << endl; // 1
    cout << *map.get(2) << endl; // 2

    map.put(1, make_shared<int>(100));
    cout << *map.get(1) << endl; // 100

    map.remove(2);
    cout << (map.get(2) == nullptr ? "null" : to_string(*map.get(2))) << endl; // null

    for (const auto key: map.keys()) {
        cout << key << " ";
    }
    // [1, 3] 顺序可能不同
    cout << endl;

    map.remove(1);
    map.remove(2);
    map.remove(3);
    cout << (map.get(1) == nullptr ? "null" : to_string(*map.get(1))) << endl; // null

    return 0;
}