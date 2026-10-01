//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

struct node {
    int val, id;
};
bool cmp(const node& x, const node& y) {
    return x.val != y.val ? x.val < y.val : x.id < y.id;
}

int main() {
    // freopen("g_sort.in", "r", stdin);
    // freopen("g_sort.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, Q, op1, op2, op3;
    vector<node> a, b;
    bool flag = true;
    scanf("%d %d", &n, &Q);
    a.push_back({0,0});
    for (int i = 1, e; i <= n; i++) scanf("%d", &e), a.push_back({e, i});
    while (Q--) {
        scanf("%d", &op1);
        if (op1 == 1) {
            // cin >> op2 >> op3;
            scanf("%d %d", &op2, &op3);
            a[op2].val = op3;
            flag = true;
            // for (int i = 1; i <= n; i++) cout << a[i].val << "[" << a[i].id << "]" << " ";
            // cout << endl;
        } else {
            scanf("%d", &op2);
            if (flag) {
                b = a;
                sort(b.begin() + 1, b.end(), cmp);
                flag = false;
            }
            // for (int i = 1; i <= n; i++) cout << a[i].val << "[" << a[i].id << "]" << " ";
            // cout << endl;
            // for (int i = 1; i <= n; i++) cout << b[i].val << "[" << b[i].id << "]" << " ";
            // cout << endl;
            for (int i = 1; i <= n; i++) if (a[op2].val == b[i].val && a[op2].id == b[i].id) { printf("%d\n", i); break; }
        }
    }
    return 0;
}