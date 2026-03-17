//
// Created by Geek.Kwok on 2026/3/16.
//
#include <bits/stdc++.h>
using namespace std;

int n, cnt, vis[25];
string str[25], ss;

int connect(string a, string b) {
    int lena = a.length();
    for (int bi = 1; bi <= b.length(); bi++) {
        // lena < bi: b 包含了 a 则返回 0 表示不能连接
        if (lena < bi) return 0;

        int f = true;
        for (int bj = 0; bj < bi; bj++) {
            // bi >= b.length() && f: a 包含了 b 则在外层会 continue
            if (lena >= bi && a[lena - bi + bj] != b[bj]) {
                f = false;
                break;
            }
        }
        if (f) return bi;
    }
    return 0;
}

void dfs(string ss) {
    cnt = max(cnt, (int)ss.length());
    for (int i = 1; i <= n; i++) {
        if (vis[i] >= 2) continue;
        int idx = connect(ss, str[i]); // 可以连接则返回连接点索引；不可以连接返回0
        if (!idx || idx >= str[i].length()) continue; // 无法连接或包含关系则继续
        vis[i]++;
        dfs(ss + str[i].substr(idx));
        vis[i]--;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
    }
    cin >> ss;
    dfs(ss);
    cout << cnt << endl;
    return 0;
}