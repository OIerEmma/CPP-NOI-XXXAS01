//
// Created by Emme.Kwok on 2026/3/28.
//
#include<bits/stdc++.h>
using namespace std;

int f[200010];
bool vis[200010];
int a, b;

int bfs() {
    queue <int> q;
    q.push(a);
    vis[a] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == b) {
            return f[now];
        }
        int nxt = now + 1;
        if (nxt >= 0 && nxt <= 100000 && vis[nxt] == false) {
            f[nxt] = f[now] + 1;
            q.push(nxt);
            vis[nxt] = true;
        }
        nxt = now - 1;
        if (nxt >= 0 && nxt <= 100000 && vis[nxt] == false) {
            f[nxt] = f[now] + 1;
            q.push(nxt);
            vis[nxt] = true;
        }
        nxt = now * 2;
        if (nxt >= 0 && nxt <= 100000 && vis[nxt] == false) {
            f[nxt] = f[now] + 1;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    return -1;
}

int main() {
    cin >> a >> b;
    cout << bfs() << endl;
    return 0;
}

/*
*
#include <bits/stdc++.h>
using namespace std;

#define N 3000001
int n, k, ans, vis[N];

int main() {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        if (now == k) {
            cout << vis[k] << endl;
            break;
        }
        if (now - 1 >= 0 && now -1 < N && !vis[now - 1]) {
            q.push(now - 1);
            vis[now - 1] = vis[now] + 1;
        }
        if (now + 1 >= 0 && now + 1 < N && !vis[now + 1]) {
            q.push(now + 1);
            vis[now + 1] = vis[now] + 1;
        }
        if (2 * now >= 0 && 2 * now < N && !vis[2 * now]) {
            q.push(2 * now);
            vis[2 * now] = vis[now] + 1;
        }
    }
    return 0;
}
*/