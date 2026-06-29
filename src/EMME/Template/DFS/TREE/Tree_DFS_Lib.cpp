//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

// 1.子树统计：统计每个节点的子树有多少个节点
const int N = 1e5 + 5;
vector<int> subtree_size(N), subtree_sum(N), depth(N), ch[N], value(N);

int dfsSize(int root) {
    int size = 1;
    for (int u : ch[root]) size += dfsSize(u);
    subtree_size[root] = size;
    return size;
}

// 2.子树求和：统计每个节点的子树所有节点的和
int dfsSum(int root) {
    int sum = value[root];
    for (int u : ch[root]) sum += dfsSum(u);
    subtree_sum[root] = sum;
    return sum;
}

// 3.求数高度
int dfsDepth(int root) {
    int maxdepth = 0;
    for (int u : ch[root])
        maxdepth = max(dfsDepth(u), maxdepth);
    depth[root] = maxdepth + 1;
    return maxdepth + 1;
}

// 4.从根到叶的路径操作：对从根到每个叶子进行某种操作
// 要素1：确定递归函数含义（参数+返回值）
void dfsAcc(int root, int acc) {
    // 要素2：递归基
    if (ch[root].empty()) return;
    for (int u : ch[root]) dfsAcc(u, acc + value[u]);
}

// 5.子树操作（如颜色反转）
vector<int> color(N, 0);
void dfs_reverse(int root) {
    color[root] = !color[root];
    for (int u : ch[root]) dfs_reverse(u);
}

int main() {

    return 0;
}