//
// Created by Amy on 2026/7/10.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long X, Y, R;
    cin >> X >> Y >> R;

    long long R2 = R * R;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long dx = x - X;
        long long dy = y - Y;
        if (dx * dx + dy * dy <= R2) {
            ++count;
        }
    }

    cout << count << "\n";
    return 0;
}
