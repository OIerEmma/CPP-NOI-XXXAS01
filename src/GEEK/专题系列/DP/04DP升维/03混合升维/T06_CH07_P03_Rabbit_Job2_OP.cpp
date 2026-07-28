//
// Created by Geek.Kwok on 7/28/26.
//
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    int n, K;
    string s;
    cin >> n >> K >> s;

    // 定义状态：滚动 pre/cur 表示「上一天 / 今天」的 dp[w][c]
    vector<vector<long long> > pre(n + 1, vector<long long>(n + 1, INF));
    vector<vector<long long> > cur(n + 1, vector<long long>(n + 1, INF));
    // 初始化：第 5 步
    pre[0][0] = 0;
    // 顺序
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= i; w++) {
            for (int c = 0; c <= n; c++) cur[w][c] = INF;
            // 第 3、4 步（逆向/拉）：今天休息 → 填 cur[w][0]
            for (int c = 0; c <= w; c++) cur[w][0] = min(cur[w][0], pre[w][c]);
            // 第 3、4 步（逆向/拉）：今天工作 → 填 cur[w][c]（c≥1）
            if (s[i - 1] == '1')
                for (int c = 1; c <= w; c++) cur[w][c] = min(cur[w][c], pre[w - 1][c - 1] + c);
        }
        pre.swap(cur);
    }

    // 答案：第 7 步
    for (int w = n; w >= 0; w--)
        for (int c = 0; c <= n; c++)
            if (pre[w][c] <= K) cout << w << endl, exit(0);

    return 0;
}