//
// Created by Geek.Kwok on 2026/4/8.
//
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m, a, b, c;
struct F {
    int a, b, c, x, y;
};
struct FCmp {
    bool operator()(const F& a, const F& b) const {
        return a.y > b.y;
    }
};
priority_queue<F, vector<F>, FCmp> heap;

int get() {
    F f = heap.top();
    heap.pop();

    // 同时push下一个值
    const int newX = f.x + 1;
    const int newY = f.a * newX * newX + f.b * newX + f.c;
    F newF = {f.a, f.b, f.c, newX, newY};
    heap.emplace(newF);

    return f.y;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        int x0 = ceil(-b / 2 / a);
        const int x = max(1, x0);
        heap.push({a, b, c, x, a * x * x + b * x + c});
    }
    for (int i = 1; i <= m; i++) {
        cout << get() << " ";
    }
    return 0;
}