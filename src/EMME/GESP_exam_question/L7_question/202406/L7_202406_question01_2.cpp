#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int col[N], num[N];
int ans, sum;

void calc(int start, int fa) {
    for (int v : g[start])
        if (fa != v) calc(v, start), num[start] += num[v];
    num[start] += col[start];
}

void dfs(int start, int fa) {
    bool flag = false;
    if (num[start] != 0 && num[start] != sum) flag = true;
    for (int v : g[start])
        if (fa != v) {
            if (num[v] != 0 && num[v] != num[start] - col[start]) flag = true;
            dfs(v, start);
        }
    if (flag && !col[start]) ans++;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i], sum += col[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc(1, 0);
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}