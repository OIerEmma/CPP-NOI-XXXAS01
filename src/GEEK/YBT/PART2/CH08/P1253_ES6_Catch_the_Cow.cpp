//
// Created by Geek.Kwok on 3/25/26.
//
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