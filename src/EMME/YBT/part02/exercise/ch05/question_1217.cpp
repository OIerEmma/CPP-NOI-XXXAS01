//
// Created by Emme.Kwok on 2026/3/16.
//
#include<iostream>
#include<cstring>
using namespace std;

bool vis[10];
char mp[10][10];
int n, k, ans;

void dfs(int step, int line) {
    if (step == k + 1) {
        ans++;
        return;
    }
    for (int i = line; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] || mp[i][j] == '.') {
                continue;
            }
            vis[j] = true;
            dfs(step + 1, i + 1);
            vis[j] = false;
        }
    }
}

int main() {
    while (true) {
        cin >> n >> k;
        if (n == -1 && k == -1) {
            break;
        }
        memset(vis, false, sizeof(vis));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
            }
        }
        dfs(1, 1);
        cout << ans << endl;
    }
    return 0;
}