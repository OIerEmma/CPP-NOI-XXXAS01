//
// Created by Emme.Kwok on 2026/4/26.
//
#include<iostream>
using namespace std;

int n;
int a[1005][1005], f[1005][1005];

int dfs(int i, int j) {
    if (f[i][j]) return f[i][j];
    if (i == n + 1) return f[i][j] = a[i][j];
    return f[i][j] = a[i][j] + max(dfs(i + 1, j), dfs(i + 1, j + 1));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) cin >> a[i][j];
    dfs(1, 1);
    cout << f[1][1] << endl;
    return 0;
}