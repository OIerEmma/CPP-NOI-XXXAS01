//
// Created by Geek.Kwok on 2026/3/21.
//
#include <bits/stdc++.h>
using namespace std;

int f[1005];

int dfs(int x) {
    if (f[x]) return f[x];
    if (x == 1) return 1;
    int ans = 1;
    for (int i = 1; i <= x/2; i++) {
        ans += dfs(i);
    }
    return f[x] = ans;
}

int main() {
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}