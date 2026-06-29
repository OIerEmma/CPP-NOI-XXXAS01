//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

// ---建树的三种方式---

// 方式1：孩子数组（多叉树）
const int N = 1e5 + 5;
vector<int> ch[N];

int main() {
    int n;
    cin >> n;
    for (int p, i = 2; i <= n; i++) {
        cin >> p;
        ch[p].push_back(i);
    }
    return 0;
}

// 方式2：左右孩子数组（二叉树）
const int N2 = 1e5 + 5;
vector<int> lch(N2, 0), rch(N2, 0);

int main2() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> lch[i] >> rch[i];
    return 0;
}

// 方式3：邻接图存树
const int N3 = 1e5 + 5;
vector<int> g[N3];

int main3() {
    int n;
    cin >> n;
    for (int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    return 0;
}

// 方式4：邻接图存树（有额外边权信息）
const int N4 = 1e5 + 5;
vector<pair<int, int>> g2[N4];

int main4() {
    int n;
    cin >> n;
    for (int x, y, l, i = 1; i < n; i++) {
        cin >> x >> y >> l;
        g2[x].push_back({y, l});
        g2[y].push_back({x, l});
    }
    return 0;
}