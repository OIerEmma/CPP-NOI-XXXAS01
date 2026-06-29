//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
vector<bool> vis(N, false);
vector<int> a(N);
void dfs(int step) {
    if (step == n + 1) {
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            a[step] = i;
            dfs(step + 1);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}