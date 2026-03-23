//
// Created by Emme.Kwok on 2026/3/17.
//
#include<iostream>
using namespace std;

int a[15], res = 11, n;
long long vis[15];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int step, int group) {
    if (step == n + 1) {
        res = min(res, group);
        return;
    }
    for (int i = 1; i <= group; i++) {
        if (gcd(vis[i], a[step]) == 1) {
            vis[i] *= a[step];
            dfs(step + 1, group);
            vis[i] /= a[step];
        }
    }
    vis[group + 1] *= a[step];
    dfs(step + 1, group + 1);
    vis[group + 1] /= a[step];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = 1;
    }
    dfs(1, 1);
    cout << res << endl;
    return 0;
}