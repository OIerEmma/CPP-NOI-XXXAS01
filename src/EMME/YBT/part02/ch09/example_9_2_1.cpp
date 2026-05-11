//
// Created by Emme.Kwok on 2026/4/26.
//
#include<iostream>
using namespace std;

int n, ans = -1;
int a[1005][1005];

void dfs(int step, int now, int j) {
    if (step == n + 1) {
        ans = max(ans, now);
        return;
    }
    dfs(step + 1, now + a[step + 1][j], j);
    dfs(step + 1, now + a[step + 1][j + 1], j + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) cin >> a[i][j];
    dfs(1, a[1][1], 1);
    cout << ans << endl;
    return 0;
}