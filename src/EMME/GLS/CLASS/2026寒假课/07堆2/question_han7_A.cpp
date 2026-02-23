//
// Created by Emme.Kwok on 2026/2/6.
//
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> h;

int main() {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        h.push(x);
    }
    int ans = 0;
    while (h.size() > 1) {
        int a = h.top();
        h.pop();
        int b = h.top();
        h.pop();
        h.push(a + b);
        ans += a + b;
    }
    cout << ans << endl;
    return 0;
}