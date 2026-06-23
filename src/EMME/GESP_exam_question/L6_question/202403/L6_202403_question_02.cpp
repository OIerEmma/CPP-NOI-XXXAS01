//
// Created by Emme.Kwok on 2026/6/23.
//
#include<iostream>
#include<vector>
using namespace std;

int n;
const int N = 15;
vector<int> p(N);
vector<bool> vis(N, false);
vector<int> a(N), b(N);
int res = 1e9;

void dfs(int step) {
    if (step == n + 1) {
        int ans = n;
        for (int i = 1; i < n; i++)
            ans += max(b[p[i]], a[p[i + 1]]);
        res = min(res, ans);
        // for (int i = 1; i <= n; i++) cout << p[i] << " ";
        // cout << endl << ans << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            p[step] = i;
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
        }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    dfs(1);
    cout << res << endl;
    return 0;
}