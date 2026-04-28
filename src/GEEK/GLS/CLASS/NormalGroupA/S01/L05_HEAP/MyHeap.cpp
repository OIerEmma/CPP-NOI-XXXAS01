//
// Created by Geek.Kwok on 2026/4/9.
//
#include <iostream>
#include <cstdio>
using namespace std;

int h[100010], n;

void up(int k) { // 把第k个结点向上调整
    while (k > 1) {
        const int i = k/2;
        if (h[k] > h[i]) {
            swap(h[k], h[i]);
            k = i;
        } else break;
    }
}

void down(int k) { // 把第k个结点向下调整
    while (k + k <= n) {
        int i = k + k;
        if (i + 1 <= n && h[i + 1] > h[i]) ++i;
        if (h[i] > h[k]) {
            swap(h[i], h[k]);
            k = i;
        } else break;
    }
}

void add(const int x) { // 添加一个值为x的元素
    ++n;
    h[n] = x;
    up(n);
}

void del(const int pos) { // 删除下标为pos的元素
    swap(h[pos], h[n]);
    --n;
    up(pos);
    down(pos);
}

int main() {
    int nums, element;
    cin >> nums;
    for (int i = 1; i <= nums; i++) {
        scanf("%d", &element);
        add(element);
    }
    for (int i = 1; i <= nums; i++) {
        printf("%d\n", h[1]);
        del(1);
    }
    return 0;
}