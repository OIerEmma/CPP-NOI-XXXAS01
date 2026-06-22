//
// Created by Emme.Kwok on 2026/6/22.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 305;
vector<int> ch[N], depth(N, 0), parent(N);
vector<bool> vis(N, false);

int getDepth(const int x) {
    return x == 0 ? 0 : getDepth(parent[x]) + 1;
}

// 递归三要素：标记以 x 为根的整棵子树
void dfs(const int x) {
    vis[x] = true; // 先序：标记当前节点
    for (auto c : ch[x]) dfs(c); // 递归每个孩子节点
}

// 判断 root 能否管理 vec 里的所有人，即x的子树是否包含全部参与者
bool check(int root, int n, const vector<int> &vec) {
    vis.assign(N, false); // 清空标记
    dfs(root); // 点亮 x 的子树
    for (int y: vec) if (!vis[y]) return false; // 有人不在子树中则不行
    return true;
}

int main() {
    int n;
    cin >> n;
    // 建树：孩子数组存树
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        ch[parent[i]].push_back(i);
    }
    for (int i = 1; i < n; i++) depth[i] = getDepth(i);

    int q; cin >> q;
    while (q--) {
        int m, mnd = n + 1;
        cin >> m;
        vector<int> vec(m);
        for (int i = 0; i < m; i++) {
            cin >> vec[i];
            if (depth[vec[i]] < mnd) mnd = depth[vec[i]];
        }
        // 倒序枚举：第一个满足深度剪枝且子树包含全部参与者即为编号最大答案
        for (int i = n - 1; i >= 0; i--)
            if (depth[i] <= mnd && check(i, n, vec)) {
                cout << i << endl; break;
            }
    }
    return 0;
}