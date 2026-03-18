//
// Created by Geek.Kwok on 2026/3/17.
//
#include <bits/stdc++.h>
using namespace std;

int m, n, k, a[11] = {1};

void dfs(int apples, int plates) {
    if (apples <= 0 && plates <= n + 1) {
        k++;
        return;
    }
    for (int i = a[plates-1]; i <= apples; i++) {
        if (i > m) continue;
        apples -= i;
        a[plates] = i;
        dfs(apples, plates + 1);
        apples += i;
    }
}

/**
 * DFS
 */
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        k = 0;
        dfs(m, 1);
        cout << k << endl;
    }
    return 0;
}