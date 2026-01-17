//
// Created by Emma on 2025/4/6.
//
#include <iostream>
#include <algorithm>
using namespace std;

int weight[50], len;

// 定义：给定目标重量w，index-1个物品的组合累计重量cur，考察物品index，返回是否存在方案的结果
bool bag(int w, int cur, int index) {
    // 不包含当前index元素
    if (w == cur) {
        // 相等则找到可行方案
        return true;
    } else if (w < cur) {
        return false;
    }
    // 包含当前index元素
    if (w == cur + weight[index]) {
        return true;
    } else if (w < cur + weight[index]) {
        return false;
    }
    if (index < len - 1) {
        // 都不满足则继续递归查找
        return bag(w, cur, index + 1) || bag(w, cur + weight[index], index + 1);
    }
    return false;
}

int main() {
    int s, n;
    scanf("%d %d", &s, &len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &weight[i]);
    }
    sort(weight, weight + len);
    if (bag(s, 0, 0)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
