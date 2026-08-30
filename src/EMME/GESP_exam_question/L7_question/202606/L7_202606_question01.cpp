//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];
bool vis[100005];

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) g[i].clear();
        memset(vis, false, sizeof vis);
        for (int i = 1, u, v; i <= n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
            if (!vis[i]) {
                int ans = 0, cur = i, pre = -1, nxt;
                while (!vis[cur]) {
                    vis[cur] = true;
                    if (pre == g[cur][0]) nxt = g[cur][1];
                    else nxt = g[cur][0];
                    pre = cur;
                    cur = nxt;
                    ans++;
                }
                if (ans % 2) {
                    cout << "3\n";
                    flag = true;
                    break;
                }
            }
        if (!flag) cout << "2\n";
    }
    return 0;
}