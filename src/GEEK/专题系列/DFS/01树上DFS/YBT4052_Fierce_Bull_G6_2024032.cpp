//
// Created by Geek.Kwok on 6/23/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, ans = 1e9;
vector<int> a(N), b(N), p(N);
vector<bool> visited(N, false);

void dfs(int depth) {
    if (depth == n) {
        int len = n;
        for (int i = 1; i < n; i++) len += max(a[p[i]], b[p[i-1]]);
        ans = min(ans, len);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true; p[depth] = i;
        dfs(depth + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    dfs(0);
    cout << ans << endl;
    return 0;
}