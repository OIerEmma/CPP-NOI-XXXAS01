//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

void dfs(int root, int now, vector<int> &sum, vector<int> &col, vector<int> ch[]) {
    now += sum[root];
    if (now & 1) col[root] ^= 1;
    for (const int child : ch[root]) dfs(child, now, sum, col, ch);
}

int main() {
    int n;
    cin >> n;
    // 建树：孩子数组
    vector<int> ch[n + 1];
    for (int p, i = 2; i <= n; i++) {
        cin >> p;
        ch[p].push_back(i);
    }

    string s; cin >> s; s = " " + s;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) color[i] = s[i] - '0';

    int q, r; cin >> q;
    vector<int> sum(n + 1, 0);
    while (q--) { cin >> r; sum[r]++; }

    // 调用DFS
    dfs(1, 0, sum, color, ch);
    // 取答案
    for (int i = 1; i <= n; i++) cout << color[i];
    cout << endl;

    return 0;
}