//
// Created by Geek.Kwok on 6/24/26.
//
#include <bits/stdc++.h>
using namespace std;

// --- 建树的三种方式 ---

// 方式1：孩子数组
const int N = 100005;
vector<int> children[N];  // children[i]存储节点i的所有孩子

int main() {
    // 读入：n个节点，第2~n行每行一个parent
    int n;
    cin >> n;
    for (int parent, i = 2; i <= n; i++) {
        cin >> parent;
        children[parent].push_back(i);
    }
    return 0;
}

// 方式2：左右孩子数组
const int N2 = 100005;
// 初始化为0表示没有孩子
vector<int> left_child(N2, 0);   // left_child[i] = 节点i的左孩子；初始化为0表示没有孩子
vector<int> right_child(N2, 0);  // right_child[i] = 节点i的右孩子；初始化为0表示没有孩子

int main2() {
    // 读入：n个节点，第2~n+1行每行左右两个孩子
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> left_child[i] >> right_child[i];
    return 0;
}

// 方式3：邻接表存树
// --- 无额外边权信息 ---
const int N3 = 2e5 + 10;
vector<int> G[N3];

int main3() {
    // 读入：n个节点，第2~n行每行一条边的两个节点
    int n;
    cin >> n;
    // 建树：邻接表存树（未告知节点父子关系时）
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    return 0;
}

// --- 有额外边权信息 ---
const int N4 = 1e5 + 10;
vector<pair<int, int>> g[N4];

int main4() {
    // 读入：n个节点，第2~n行每行一条边的两个节点及边权值
    int n;
    cin >> n;
    // 建树：邻接表存树（当未告知节点父子关系时）
    for (int u, v, w, i = 1; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    return 0;
}


// --- 树上DFS模板 ---

const int N5 = 100005;
vector<int> ch[N5], info(N5);
int new_state;
int combine(int a, int b);

// 要素一：确定递归函数的含义（参数 + 返回值）
// 简单模板
void dfs(int u) {
    // 要素二：递归基
    // 要素三A：处理当前节点 u
    cout << u << " ";
    // 要素三B：递归处理所有孩子
    for (int v : ch[u]) {
        dfs(v);
    }
}

int main5() {
    int n;
    cin >> n;
    // 建树
    for (int parent, i = 2; i <= n; i++) {
        cin >> parent;
        ch[parent].push_back(i);
    }
    // DFS
    dfs(1);  // 从根节点1开始
    // 答案
    return 0;
}

// 带状态传递模板：先序 + 参数
void dfs(int u, int state) {
    // state 是从根传下来的信息
    // 例如：从根到当前节点的路径长度、累积和等

    // 要素三A：处理当前节点
    // ...

    // 要素三B：递归处理所有孩子，传递新的状态
    for (int v : ch[u]) {
        dfs(v, new_state);  // new_state 根据题目计算
    }
}

// 带返回值模板：后续 + 返回值
int dfs2(int u) {
    // 要素二：递归基，如果是叶子节点
    if (ch[u].empty()) return info[u];  // 返回叶子节点的值

    // 要素三B：递归处理所有孩子，收集返回值
    int result = 0;  // 初始值
    for (int v : ch[u]) {
        result = combine(result, dfs2(v));  // 要素三A：合并子树的结果
    }

    // 返回值：以u为根的子树的某种信息
    return result;
}


// --- 树上DFS常见题型模板 ---
// 1子树统计：统计每个节点的子树有多少个节点
vector<int> subtree_size(N);

int dfsSize(int u) {
    int size = 1;  // 自己算1个
    for (int v : children[u]) {
        size += dfsSize(v);  // 加上每个子树的大小
    }
    subtree_size[u] = size;
    return size;
}

// 2子树求和：求每个节点的子树中所有节点的值之和
vector<int> val(N);  // 每个节点的值
vector<int> subtree_sum(N);

int dfsSum(int u) {
    int sum = val[u];  // 从自己的值开始
    for (int v : children[u]) {
        sum += dfsSum(v);  // 加上每个子树的和
    }
    subtree_sum[u] = sum;
    return sum;
}

// 3求树的高度/深度
vector<int> depth(N);

int dfsDepth(int u) {
    int max_depth = 0;
    for (int v : children[u]) {
        max_depth = max(max_depth, dfsDepth(v)); // 找出所有子树中最大高度/深度
    }
    depth[u] = max_depth + 1; // 树的高度/深度=所有子树的最大高度/深度+1
    return depth[u];
}

// 4从根到叶的路径操作：对从根到每个叶子的路径进行某种操作
void dfsAcc(int u, int accumulated) {
    // accumulated 是从根到当前节点的累积值

    // 要素二：如果是叶子节点，使用累积值
    if (children[u].empty()) {
        // 用 accumulated 做某事
        return;
    }

    // 要素三B：递归处理孩子
    for (int v : children[u]) {
        dfsAcc(v, accumulated + val[v]);  // 累加上孩子节点的值
    }
}

// 5子树操作（如颜色反转）
vector<int> color(N);  // 每个节点的颜色

void reverse_subtree(int u) {
    color[u] = 1 - color[u];  // 反转当前节点颜色
    for (int v : children[u]) {
        reverse_subtree(v);     // 递归反转子树
    }
}