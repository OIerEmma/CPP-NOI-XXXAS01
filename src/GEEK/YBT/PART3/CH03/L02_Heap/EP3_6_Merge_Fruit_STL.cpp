//
// Created by Geek.Kwok on 2026/3/28.
//
#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int , vector<int>, greater<int>> h;

void work() {
    int i, x, y, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        h.push(x);
    }
    for (i = 1; i < n; i++) {
        x = h.top(); h.pop();
        y = h.top(); h.pop();
        ans += x + y;
        h.push(x + y);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    work();
    return 0;
}