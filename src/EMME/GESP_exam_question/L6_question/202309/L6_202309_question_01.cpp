//
// Created by Emme.Kwok on 2026/4/23.
//
#include<iostream>
using namespace std;

int n, L, ans = INT32_MAX;
int c[505], l[505], a[505];

void dfs(int step, int total, int money) {
    // cout << step << " " << total << " " << money << endl;
    if (money >= ans) return;
    if (step == n + 1) {
        if (total >= L) ans = min(ans, money);
        return;
    }
    for (int i = 1; i >= 0; i--) {
        a[step] = i;
        dfs(step + 1, total + (i ? l[step] : 0), money + (i ? c[step] : 0));
        a[step] = 0;
    }
}

int main() {
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> l[i];
    }
    dfs(1, 0, 0);
    if (ans == INT32_MAX) cout << "no solution\n";
    else cout << ans << endl;
    return 0;
}