//
// Created by Emme.Kwok on 2026/8/25.
//
#include<queue>
#include<vector>
using namespace std;

vector<int> g[105];
int dist[105];

void bfsDist(int start, int n) {
    for (int i = 1; i <= n; i++) dist[i] = -1;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}