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
void myswap(node& x, node& y) {
    const node t = x;
    x = y;
    y = t;
}
int main() {
    // freopen("g_sort.in", "r", stdin);
    // freopen("g_sort.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, Q, op1, op2, op3;
    vector<node> a, b;
    scanf("%d %d", &n, &Q);
    a.push_back({0,0}); b.push_back({0,0});
    for (int i = 1, e; i <= n; i++) {
        scanf("%d", &e);
        a.push_back({e, i}); b.push_back({e, i});
    }
    sort(b.begin() + 1, b.end(), cmp);
    while (Q--) {
        scanf("%d", &op1);
        if (op1 == 1) {
            // cin >> op2 >> op3;
            scanf("%d %d", &op2, &op3);
            // 在排序数组 b 里通过左右 myswap 调整为有序
            // (1)先找到对应的位置点
            int pos;
            for (pos = 1; pos <= n; pos++) {
                if (b[pos].val == a[op2].val && b[pos].id == a[op2].id) break;
            }
            // (2)更新位置点的值
            b[pos].val = op3;
            // (3)进行两个方向的swap
            for (int i = pos; i > 1; i--)
                if (b[i-1].val > b[i].val || (b[i-1].val == b[i].val && b[i-1].id > b[i].id))
                    myswap(b[i-1], b[i]);
                else break;
            for (int i = pos; i < n; i++)
                if (b[i].val > b[i+1].val || (b[i].val == b[i+1].val && b[i].id > b[i+1].id))
                    myswap(b[i], b[i+1]);
                else break;
            // 更新原数组 a
            a[op2].val = op3;
            // for (int i = 1; i <= n; i++) cout << a[i].val << "[" << a[i].id << "]" << " ";
            // cout << endl;
            // for (int i = 1; i <= n; i++) cout << b[i].val << "[" << b[i].id << "]" << " ";
            // cout << endl;
        } else {
            scanf("%d", &op2);
            for (int i = 1; i <= n; i++) if (a[op2].val == b[i].val && a[op2].id == b[i].id) { printf("%d\n", i); break; }
        }
    }
    return 0;
}