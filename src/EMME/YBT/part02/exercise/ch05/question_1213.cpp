//
// Created by Emme.Kwok on 2026/3/15.
//
#include<iostream>
using namespace std;

int ans[10][10], vis[10], vis1[20], vis2[20], cnt;

void dfs(int step) {
    if (step == 9) {
        cout << "No. " << ++cnt << endl;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cout << ans[j][i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (vis[i] || vis1[step + i - 1] || vis2[step - i + 8]) {
            continue;
        }
        vis[i] = vis1[step + i - 1] = vis2[step - i + 8] = 1;
        ans[step][i] = 1;
        dfs(step + 1);
        ans[step][i] = 0;
        vis[i] = vis1[step + i - 1] = vis2[step - i + 8] = 0;
    }
}

int main() {
    dfs(1);
    return 0;
}