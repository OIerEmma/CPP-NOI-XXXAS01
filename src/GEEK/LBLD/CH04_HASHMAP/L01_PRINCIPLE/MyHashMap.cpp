//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    vector<void*> table;

    // 哈希函数，把 key 转化成 table 中的合法索引
    // 时间复杂度必须是O(1)才能保证上述方法的复杂度都是O(1)
    int hash(auto key) {
        // ...
    }

public:
    // 增/改，复杂度O(1)
    void put(auto key, auto value) {
        int index = hash(key);
        table[index] = value;
    }

    // 查，复杂度O(1)
    auto get(auto key) {
        int index = hash(key);
        return table[index];
    }

    // 删，复杂度O(1)
    void remove(auto key) {
        int index = hash(key);
        table[index] = nullptr;
    }
};

int main() {

    return 0;
}