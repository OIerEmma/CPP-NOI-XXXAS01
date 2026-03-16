//
// Created by Geek.Kwok on 2026/3/16.
//
#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
bool visc[10];
char mp[10][10];

void dfs(int row, int step) {
    if (step == k + 1) {
        cnt++;
        return;
    }
    for (int i = row; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] == '.' || visc[j]) continue;
            visc[j] = true;
            dfs(i + 1, step + 1);
            visc[j] = false;
        }
    }
}

int main() {
    do {
        cin >> n >> k;
        if (n == -1 && k == -1) {
            break;
        }
        memset(visc, false, sizeof(visc));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
            }
        }
        cnt = 0;
        dfs(1, 1);
        cout << cnt << endl;
    } while (true);
    return 0;
}