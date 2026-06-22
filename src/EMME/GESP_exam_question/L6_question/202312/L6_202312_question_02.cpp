//
// Created by Emme.Kwok on 2026/6/21.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 305;
int fa[N], dep[N];
bool vis[N];
vector<int> ch[N];

int getdep(int x) {
    return x == 0 ? 0 : getdep(fa[x]) + 1;
}

void dfs(int x) {
    vis[x] = true;
    for (int y : ch[x]) dfs(y);
}

bool check(int x, int n, const vector<int>& vec) {
    for (int i = 0; i <= n; i++) vis[i] = false;
    dfs(x);
    for (int y : vec) if (!vis[y]) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> fa[i];
        ch[fa[i]].push_back(i);
    }
    for (int i = 1; i < n; i++) dep[i] = getdep(i);
    int q;
    cin >> q;
    while (q--) {
        int m, mnd = n + 1;
        cin >> m;
        vector<int> vec(m);
        for (int i = 0; i < m; i++) {
            cin >> vec[i];
            mnd = min(mnd, dep[vec[i]]);
        }
        for (int i = n - 1; i >= 0; i--)
            if (dep[i] <= mnd && check(i, n, vec)) {
                cout << i << endl;
                break;
            }
    }
    return 0;
}