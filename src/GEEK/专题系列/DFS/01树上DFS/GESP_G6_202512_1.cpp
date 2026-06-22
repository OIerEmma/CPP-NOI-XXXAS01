//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> ch[N], c(N);

long long dfs(int root) {
    if (ch[root].empty()) return c[root];
    long long sum = 0;
    for (int child: ch[root]) sum += dfs(child);
    return min(static_cast<long long>(c[root]), sum);
}

int main() {
    int n;
    cin >> n;
    // 建树：孩子数组存树
    for (int p, i = 2; i <= n; i++) {
        cin >> p;
        ch[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    // 调用DFS & // 取答案
    cout << dfs(1) << endl;
    return 0;
}