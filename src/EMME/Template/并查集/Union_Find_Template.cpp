//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

int fa[100005];

void init(int n) {  // ① 一开始每个人自己当队长
    for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int x) {  // ② 找 x 的队长（根），带路径压缩
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void unite(int a, int b) {  // ③ 把 a、b 两团合并
    fa[find(a)] = find(b);
}

bool isconnected(int a, int b) {  // ④ 判断 a、b 是否连通
    return find(a) == find(b);
}

int main() {
    return 0;
}