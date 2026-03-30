//
// Created by Geek.Kwok on 2026/3/30.
//
#include <iostream>
using namespace std;

int n, heap_size;
int heap[100001];

void put(const int d) {
    heap[++heap_size] = d;
    int now = heap_size;
    while (now > 1) {
        const int next = now >> 1;
        if (heap[now] >= heap[next]) return;
        swap(heap[now], heap[next]);
        now = next;
    }
}

int get() {
    const int res = heap[1];
    heap[1] = heap[heap_size--];
    int now = 1;
    while (now * 2 <= heap_size) {
        int next = now * 2;
        if (next < heap_size && heap[next + 1] < heap[next]) next++;
        if (heap[now] <= heap[next]) return res;
        swap(heap[now], heap[next]);
        now = next;
    }
    return res;
}

void work() {
    int x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        put(x);
    }
    for (int i = 1; i < n; i++) {
        cout << get() << " ";
    }
    cout  << get() << endl;
}

int main() {
    work();
    return 0;
}