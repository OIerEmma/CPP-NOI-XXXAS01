//
// Created by Emme.Kwok on 2026/6/23.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> l(N), r(N);
vector<int> chk(N), mn(N), mx(N);
int ans;

void dfs(int root) {
    chk[root] = 1;
    if (!root) return;
    dfs(l[root]);
    dfs(r[root]);
    chk[root] &= chk[l[root]] & chk[r[root]];
    mn[root] = min(mn[l[root]], mn[r[root]]) + 1;
    mx[root] = max(mx[l[root]], mx[r[root]]) + 1;
    chk[root] &= mn[l[root]] >= mx[r[root]]; // ???
    chk[root] &= mn[root] >= mx[root] - 1;
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