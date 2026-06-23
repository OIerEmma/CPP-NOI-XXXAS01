//
// Created by Emme.Kwok on 2026/6/23.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> ch[N];
vector<int> c(N);

long long dfs(int root) {
    long long ans = 0;
    if (ch[root].empty()) return c[root];
    for (int c : ch[root]) ans += dfs(c);
    return min((long long)c[root], ans);
}

int main() {
    int n;
    cin >> n;
    // 建树：孩子数组
    for (int p, i = 2; i <= n; i++) cin >> p, ch[p].push_back(i);
    for (int i = 1; i <= n; i++) cin >> c[i];
    // 调用DFS / 取答案
    cout << dfs(1) << endl;
    return 0;
}