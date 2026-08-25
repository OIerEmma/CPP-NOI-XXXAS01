//
// Created by Emme.Kwok on 2026/8/20.
//
#include<bits/stdc++.h>
using namespace std;

const long long NEG = -1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long> > a(n + 1, vector<long long>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    vector<vector<long long> > pre(n + 2, vector<long long>(3, NEG));
    vector<vector<long long> > cur(n + 2, vector<long long>(3, NEG));
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) cur[i][0] = cur[i][1] = cur[i][2] = NEG;
        if (j == 1) cur[1][0] = cur[1][1] = cur[1][2] = a[1][1];
        for (int i = 1; i <= n; i++) {
            if (j > 1) {
                long long pre_best = max(pre[i][0], max(pre[i][1], pre[i][2]));
                if (pre_best != NEG)
                    cur[i][0] = max(cur[i][0], pre_best + a[i][j]);
            }
            if (i > 1) {
                long long up = max(cur[i - 1][0], cur[i - 1][1]);
                if (up != NEG)
                    cur[i][1] = max(cur[i][1], up + a[i][j]);
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            long long down = max(cur[i + 1][0], cur[i + 1][2]);
            if (down != NEG)
                cur[i][2] = max(cur[i][2], down + a[i][j]);
        }
        pre.swap(cur);
    }
    long long ans = max(pre[n][0], max(pre[n][1], pre[n][2]));
    cout << ans << endl;
    return 0;
}