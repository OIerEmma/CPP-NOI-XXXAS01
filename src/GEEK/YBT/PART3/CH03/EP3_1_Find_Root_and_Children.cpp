//
// Created by Geek.Kwok on 2026/3/22.
//
#include <bits/stdc++.h>
using namespace std;

int n, m, tree[101] = {0};

int main() {
    int i, j, x, y, root, maxroot, sum = 0, Max = 0;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        tree[y] = x;
    }
    for (i = 1; i <= n; i++) {
        if (tree[i] == 0) {
            root = i; break; // 找树根
        }
    }
    for (i = 1; i <= n; i++) {
        sum = 0;
        for (j = 1; j <= n; j++) {
            if (tree[j] == i) sum++;
        }
        if (sum > Max) {
            Max = sum; maxroot = i;
        }
    }
    cout << root << endl << maxroot << endl;
    for (i = 1; i <= n; i++) {
        if (tree[i] == maxroot) cout << i << " ";
    }
    return 0;
}