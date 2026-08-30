//
// Created by Emme.Kwok on 2026/8/30.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN], tr(MAXN), num(MAXN);
int ans, sum;

void calc(int start, int fa) {
    num[start] += tr[start];
    for (int v : g[start])
        if (fa != v) calc(v, start), num[start] += num[v];
}

void dfs(int start, int fa) {
    bool flag = false;
    if (num[start] != 0 && num[start] != sum) flag = true;
    for (int v : g[start])
        if (fa != v) {
            dfs(v, start);
            if (num[v] != 0 && num[v] != num[start] - tr[start]) flag = true;
        }
    cout << start << " " << flag << endl;
    if (flag) ans++;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ans = sum = 0;
        for (int i = 1; i <= n; i++) cin >> tr[i], sum += tr[i];
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        fill(num.begin(), num.end(), 0);
        calc(1, 0);
        dfs(1, 0);
        cout << (ans ? "No" : "Yes") << endl;
    }
    return 0;
}