//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

// DFS简单模版
const int N = 1e5 + 5;
vector<int> ch[N], value(N), info(N);
long long ans;

// 要素1：确定递归函数含义（参数 + 返回值）
void dfs(int root) {
    // 要素2：递归基（如有必要）
    // 要素3A：处理当前节点u
    cout << root << " ";
    // 要素3B：怎么递归孩子
    for (int u : ch[root]) dfs(u);
}

int main() {
    // 1.建树
    int n;
    cin >> n;
    for (int p, i = 2; i <= n; i++) {
        cin >> p;
        ch[p].push_back(i);
    }
    // 2.调用DFS
    dfs(1);
    // 3.取答案
    cout << ans << endl;
    return 0;
}

// 带状态的传递模版：先序+参数
// 要素1：确定递归函数的含义：参数+返回值
void dfs2(int root, int state) {
    // state是从根传下来的信息，如：从根到当前阶段的路径长度、累计和等
    // 要素2：递归基（如有必要）
    // 要素3A：处理当前节点
    cout << root << " ";
    // 要素3B：怎么递归孩子
    for (int u : ch[root]) dfs2(u, state + value[u]);
}

int combine(int a, int b);
// 带返回值的模版：后序+返回值
// 要素1：确定递归函数的含义：参数+返回值
int dfs3(int root) {
    // 要素2：递归基（如有必要）
    if (ch[root].empty()) return value[root];
    // 要素3B：怎么递归孩子？
    int ans = 0;
    for (int u : ch[root]) ans = combine(ans, dfs3(u));
    // 要素3A：处理当前节点
    return ans;
}