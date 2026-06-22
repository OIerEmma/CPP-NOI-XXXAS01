//
// Created by Emme.Kwok on 2026/6/22.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> G[N];
int bel[N], cnt[2];

// 递归三要素：DFS + 参数：把 u 染成 c，邻居染 c ^ 1（先序 + 参数下传）
void dfs(int root, int color, int parent) {
    // if () return; 递归基
    // 要素三：对当前节点要做什么？ 放在先序还是后序？
    bel[root] = color;
    cnt[color]++;
    // 要素三：怎么递归孩子？
    for (int v : G[root]) if (v != parent) dfs(v, color ^ 1, root);
}

int main() {
    int n;
    scanf("%d", &n);
    // 建树：邻接表存树
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // 调用DFS
    dfs(1, 0, 0);
    // " \n"[i == n] 作用是：i == n 满足条件时为 true(1) 时，取下标为一的'\n'
    // 不满足 false(0)，取下标为零的' '
    // " \n"[i == n] 等同于不是最后一个就输出空格，是最后一个就输出换行
    // 取答案
    for (int i = 1; i <= n; i++) printf("%d%c", cnt[bel[i]], " \n"[i == n]);
    return 0;
}