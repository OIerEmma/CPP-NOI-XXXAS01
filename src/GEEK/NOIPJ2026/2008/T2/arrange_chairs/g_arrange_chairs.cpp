//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector<int> row(MAXN, 0), rpos, col(MAXN, 0), cpos;

bool cmp(int x, int y) {
    if (row[x] != row[y]) return row[x] > row[y];
    return x < y;
}
bool cmp2(int x, int y) {
    if (col[x] != col[y]) return col[x] > col[y];
    return x < y;
}

int main() {
    // freopen("g_arrange_chairs.in", "r", stdin);
    // freopen("g_arrange_chairs.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int M, N, K, L, D;
    cin >> M >> N >> K >> L >> D;
    for (int i = 0, x, y, p, q; i < D; i++) {
        cin >> x >> y >> p >> q;
        if (x == p) col[min(y,q)]++;
        else if (y == q) row[min(x, p)]++;
    }
    // for (int i = 1; i < M; i++) cout << row[i] << " "; cout << endl;
    // for (int i = 1; i < N; i++) cout << col[i] << " "; cout << endl;
    // 行索引排序
    rpos.clear();
    for (int i = 1; i < M; i++) rpos.push_back(i);
    sort(rpos.begin(), rpos.end(), cmp);
    rpos.resize(min(K, (int)rpos.size()));
    sort(rpos.begin(), rpos.end());
    // 列索引排序
    cpos.clear();
    for (int i = 1; i < N; i++) cpos.push_back(i);
    sort(cpos.begin(), cpos.end(), cmp2);
    cpos.resize(min(L, (int)cpos.size()));
    sort(cpos.begin(), cpos.end());
    // for (int i = 1; i < M; i++) cout << rpos[i] << " "; cout << endl;
    // for (int i = 1; i < N; i++) cout << cpos[i] << " "; cout << endl;
    // 输出
    for (int i = 0; i < (int)rpos.size(); i++) {
        if (i) cout << " "; cout << rpos[i];
        // if (i == (int)rpos.size() - 1) cout << endl;
    }
    cout << endl;
    for (int i = 0; i < (int)cpos.size(); i++) {
        if (i) cout << " "; cout << cpos[i];
        // if (i == (int)cpos.size() - 1) cout << endl;
    }
    cout << endl;
    return 0;
}