//
// Created by Emme.Kwok on 2026/9/28.
//
#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pq.push(a[i]);
    long long ans = 0;
    while (pq.size() > 1) {
        int h = pq.top();
        pq.pop();
        int h2 = pq.top();
        pq.pop();
        pq.push(h + h2);
        ans += h + h2;
    }
    cout << ans << endl;
    return 0;
}