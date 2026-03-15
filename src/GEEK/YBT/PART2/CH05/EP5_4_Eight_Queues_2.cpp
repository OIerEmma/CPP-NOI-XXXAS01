//
// Created by Geek.Kwok on 2026/3/15.
//
#include <bits/stdc++.h>
using namespace std;

int a[20], vis[20], visl[20], visr[20], total;

void dfs(int row) {
    if (row > 8) {
        cout << "No. " << ++total << endl;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (a[j] == i) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
        return;
    }

    for (int j = 1; j <= 8; j++) {
        if (vis[j] || visl[j + row] || visr[row - j + 7]) continue;
        a[row] = j;
        visr[row - j + 7] = visl[j + row] = vis[j] = 1;
        dfs(row + 1);
        visr[row - j + 7] = visl[j + row] = vis[j] = 0;
    }
}

int main() {
    dfs(1);
    return 0;
}