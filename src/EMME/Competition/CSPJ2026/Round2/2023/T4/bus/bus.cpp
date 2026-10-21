//
// Created by Emme.Kwok on 2026/10/14.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 2e4 + 5;
vector<pair<int, int>> g[M];
vector<int> dist[N];

void bfs() {
    queue<int> q;
    q.push(1);

}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1, u, v, a; i <= n; i++) {
        cin >> u >> v >> a;
        g[u].push_back({v, a});
    }
    for (int i = 1; i <= n; i++) {

    }
    return 0;
}