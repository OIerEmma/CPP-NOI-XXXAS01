//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

int main() {
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // ...解题...
    return 0;
}

// 提交前检查清单：
// 1.检查 文件名 是不是对
// 2.检查 long long 要不要开
// 3.检查 数组 够不够大
// 4.检查 多组数据 清空了 没有 ⭐️
// 5.检查 调试输出 删除了 没有 ⭐️
// 6.检查 样例和自己造的边界数据 通过了 没有