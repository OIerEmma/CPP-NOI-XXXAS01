//
// Created by Emme.Kwok on 2026/3/15.
//
#include<iostream>
using namespace std;

int vis[10], vis1[20], vis2[20], cnt, x, a[20];
bool flag = false;

void dfs(int step) {
    if (step == 9) {
        cnt++;
        if (cnt == x) {
            for (int i = 1; i <= 8; i++) {
                cout << a[i];
            }
            cout << "\n";
            flag = true;
        }
        return;
    }
    if (flag) return;
    for (int i = 1; i <= 8; i++) {
        if (vis[i] || vis1[step + i - 1] || vis2[step - i + 8]) {
            continue;
        }
        vis[i] = vis1[step + i - 1] = vis2[step - i + 8] = 1;
        a[step] = i;
        dfs(step + 1);
        a[step] = 0;
        vis[i] = vis1[step + i - 1] = vis2[step - i + 8] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> x;
        cnt = 0;
        flag = false;
        dfs(1);
    }
    return 0;
}