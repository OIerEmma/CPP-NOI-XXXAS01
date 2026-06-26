//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> l(N), r(N);
vector<int> chk(N), mn(N), mx(N);
int ans;

void dfs(int root) {
    chk[root] = 1;
    if (!root) return; // 空子树：chk=1, mn=0, mx=0
    dfs(l[root]); dfs(r[root]);
    chk[root] &= chk[l[root]] & chk[r[root]]; // 条件1：左右子树都完全
    mn[root] = 1 + min(mn[l[root]], mn[r[root]]);
    mx[root] = 1 + max(mx[l[root]], mx[r[root]]);
    chk[root] &= mn[l[root]] >= mx[r[root]]; // 条件2：左不浅于右（非对称）
    chk[root] &= mn[root] >= mx[root] - 1;   // 条件3：最浅与最深差小于等于1
    ans += chk[root];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    dfs(1);
    cout << ans << endl;
    return 0;
}