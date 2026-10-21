//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 505, K = 105;
// 状态：dp[i][j]代表以i为结尾，已经添加k个的最大符合条件顶点序列的长度
int dp[N][K];
struct node {
    int x, y;
} p[N];

bool cmp(node a, node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    sort(p + 1, p + n + 1, cmp);
    // for (int i = 1; i <= n; i++) cout << p[i].x << " " << p[i].y << "\n";
    // cout << "\n";
    // for (int i = 1; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= k; s++) dp[i][s] = s + 1;
        for (int j = 1; j < i; j++) {
            if (p[i].y < p[j].y) continue;
            int gap = p[i].x - p[j].x + p[i].y - p[j].y - 1;
            // if (gap > k) continue;
            for (int s = gap; s <= k; s++)
                dp[i][s] = max(dp[i][s], dp[j][s - gap] + gap + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}