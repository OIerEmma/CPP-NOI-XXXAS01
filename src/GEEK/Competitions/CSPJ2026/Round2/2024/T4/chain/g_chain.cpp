//
// Created by Geek.Kwok on 2026/10/21.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, MAXV = 100005;
const int NONE = -1, MANY = -2;
vector<int> S[MAXV];
int prv[MAXN], cur[MAXN]; // 上一轮/这一轮以 c 结尾的人
bool ok[105][MAXN]; // ok[r][c] 恰好 r 轮、以 c 结尾是否可能

int main() {
    // freopen("g_chain.in", "r", stdin); freopen("g_chain.out", "w", stdout);
    // ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
    for (int c = 0; c < MAXN; c++) prv[c] = cur[c] = NONE;
    int T; // cin >> T;
    scanf("%d", &T);
    while (T--) {
        int n, k, q; // cin >> n >> k >> q;
        scanf("%d %d %d", &n, &k, &q);
        for (int i = 1, l; i <= n; i++) {
            scanf("%d", &l); S[i].assign(l, 0); // 初始化l个位置为0
            for (int j = 0; j < l; j++) scanf("%d", &S[i][j]);
        }
        // 先读入所有查询，记录最大需要的轮数
        vector<pair<int,int>> queries(q);
        int maxR = 0;
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &queries[i].first, &queries[i].second);
            if (queries[i].first > maxR) maxR = queries[i].first;
        }
        vector<int> prvTouched, curTouched; // 记下改过的位置，清空这些即可
        vector<pair<int, int>> okTouched; // 记录被设为 true 的 [r,c]
        for (int r = 1; r <= maxR; r++) {
            // 上一轮没有任何可达数字则后续轮次也不可能，此时提前结束
            if (r > 1 && prvTouched.empty()) break;

            for (int p = 1; p <= n; p++) {
                int lastStart = -1; // p的序列S里最近一个能当开头的下标
                for (int j = 0; j < (int)S[p].size(); j++) {
                    int x = S[p][j];
                    // 先判断结尾，开头要在 [j-k+1,j-1] 里
                    if (lastStart != -1 && j - lastStart <= k - 1) {
                        if (cur[x] == NONE) cur[x] = p, curTouched.push_back(x);
                        else if (cur[x] != p) cur[x] = MANY;
                    }
                    // 再判断开头
                    bool canStart = false;
                    if (r == 1) canStart = (x == 1);
                    else canStart = (prv[x] == MANY) || (prv[x] != NONE && prv[x] != p);
                    if (canStart) lastStart = j;
                }
            }
            for (int c : prvTouched) prv[c] = NONE; prvTouched.clear(); // 忘掉第 r-1 轮

            for (int c : curTouched) { // 第 r 轮变成上一轮
                if (!ok[r][c]) ok[r][c] = true, okTouched.push_back({r, c});
                prv[c] = cur[c], cur[c] = NONE;
                prvTouched.push_back(c);
            }
            curTouched.clear();
        }
        for (pair<int, int> p : queries) { // 询问查表
            printf("%d\n", ok[p.first][p.second] ? 1 : 0);
        }
        // 为下一组数据清空
        for (int c : prvTouched) prv[c] = NONE; prvTouched.clear();
        // 精准清理 ok 数组
        for (const auto &pr: okTouched) ok[pr.first][pr.second] = false;
        okTouched.clear();
    }
    return 0;
}