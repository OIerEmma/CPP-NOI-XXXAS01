//
// Created by Geek.Kwok on 2026/9/23.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_power.in", "r", stdin);
    // freopen("g_power.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n;
    vector<bool> f;
    cin >> n;
    if (n <= 0 || n % 2 == 1) cout << -1 << endl;
    else {
        while (n > 0) {
            f.push_back(n & 1);
            n >>= 1;
        }
        bool first = true;
        for (int i = (int)f.size() - 1; i > 0; i--) {
            if (f[i]) {
                if (!first) cout << " ";
                first = false;
                cout << (1 << i);
            }
        }
        cout << endl;
    }
    return 0;
}