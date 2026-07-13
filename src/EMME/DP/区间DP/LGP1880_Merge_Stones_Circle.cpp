//
// Created by Emme.Kwok on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1), s(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) a[n + i] = a[i], s[n + i] = s[n + i - 1] + a[n + i];
    vector<vector<int>> dp_max(2 * n + 1, vector<int>(2 * n + 1, 0));
    vector<vector<int>> dp_min(2 * n + 1, vector<int>(2 * n + 1, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            dp_min[i][j] = INF;
            for (int k = i; k < j; k++) {
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + s[j] - s[i - 1]);
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    int ans_min = INF, ans_max = 0;
    for (int i = 1; i <= n; i++)
        ans_max = max(ans_max, dp_max[i][n + i - 1]), ans_min = min(ans_min, dp_min[i][n + i - 1]);
    cout << ans_min << endl << ans_max << endl;
    return 0;
}