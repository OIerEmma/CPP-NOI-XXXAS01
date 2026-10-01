//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int d[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    set<pair<int, int>> us;
    int T; cin >> T;
    while (T--) {
        int n, m, k, x0, y0, d0;
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        vector<string> mp(n); // mp 0-based
        us.clear();
        for (int i = 0; i < n; i++) cin >> mp[i];
        // 机器人开始在地图上行走
        int step = 1; us.insert({x0, y0});
        for (int i = 1; i <= k; i++) {
            // (1)探测下一步的位置
            int nx = x0 + d[d0][0], ny = y0 + d[d0][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx-1][ny-1] == '.') {
                // (2)若是空地位置直接走上去
                if (!us.count({nx, ny})) us.insert({nx, ny}), step++;
                x0 = nx, y0 = ny;
            } else {
                // (3)非法位置则拐个弯
                d0 = (d0 + 1) % 4;
            }
        }
        cout << step << endl;
    }
    return 0;
}