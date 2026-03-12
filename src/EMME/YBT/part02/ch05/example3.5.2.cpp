//
// Created by Emme.Kwok on 2025/12/28.
//
#include<iostream>
#include<iomanip>
using namespace std;

int n, a[25], m;
bool vis[25];

void dfs(int step) {
    if (step == m + 1) {
        for (int i = 1; i <= m; i++) {
            cout << setw(3) << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && i > a[step - 1]) {
            a[step] = i;
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
            a[step] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}