//
// Created by Emme.Kwok on 2026/8/29.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[505];
set<int> s;

void bfs(int start, int k) {
    queue<int> q;
    int step = 0;
    while (step < k) {
        if (q.empty()) q.push(start);
        s.clear();
        int levelSize = (int)q.size();
        for (int i = 1; i <= levelSize; i++) {
            int now = q.front();
            q.pop();
            for (int v : g[now])
                if (!s.count(v)) q.push(v), s.insert(v);
        }
        cout << q.size() << " ";
        step++;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, k);
        cout << endl;
    }
    return 0;
}