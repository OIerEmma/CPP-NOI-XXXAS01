//
// Created by Geek.Kwok on 2026/3/28.
//
#include <iostream>
#include <cstdio>
using namespace std;

int n, heap[30001], heap_size;

void put(int d) {
    int son, pa;
    heap[++heap_size] = d;
    son = heap_size;
    while (son > 1) {
        pa = son >> 1;
        if (heap[son] >= heap[pa]) break;
        swap(heap[son], heap[pa]);
        son = pa;
    }
}

int get() {
    int pa, son, res;
    res = heap[1];
    heap[1] = heap[heap_size--];
    pa = 1;
    while (pa * 2 <= heap_size) {
        son = pa * 2;
        if (son < heap_size && heap[son + 1] < heap[son]) son++;
        if (heap[pa] <= heap[son]) break;
        swap(heap[pa], heap[son]);
        pa = son;
    }
    return res;
}

void work() {
    int i, x, y, ans = 0;
    cin >> n;
    // 建堆：其实直接将数组排序也是建堆方法之一
    for (i = 1; i <= n; i++) {
        cin >> x;
        put(x);
    }
    // 取、统计、插入
    for(i = 1; i < n; i++) {
        x = get();
        y = get();
        ans += x + y;
        put(x + y);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    work();
    return 0;
}