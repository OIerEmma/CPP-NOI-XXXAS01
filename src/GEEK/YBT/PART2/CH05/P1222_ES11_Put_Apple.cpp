//
// Created by Geek.Kwok on 2026/3/17.
//
#include <bits/stdc++.h>
using namespace std;

int m, n, k;

void dfs(int step, int p) {
    if (p > n) return;
    if (step >= m + 1) {
        k++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        dfs(step + 1, i);
    }

    dfs(step + 1, n + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
    }
    k = 0;
    dfs(1, 1);
    cout << k << endl;
    return 0;
}