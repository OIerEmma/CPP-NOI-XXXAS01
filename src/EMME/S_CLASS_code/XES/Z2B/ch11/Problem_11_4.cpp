//
// Created by Emme.Kwok on 2026/1/10.
//
#include<iostream>
using namespace std;

const int maxn = 15;
int n, k, res, a[maxn];
bool g[maxn][maxn], vis[maxn];

void dfs(int step) {
    if (step == n + 1) {
        res++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !g[i][a[step - 1]]) {
            a[step] = i;
            vis[i] = true;
            dfs(step + 1);
            a[step] = 0;
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = true;
    }
    dfs(1);
    cout << res << endl;
    return 0;
}