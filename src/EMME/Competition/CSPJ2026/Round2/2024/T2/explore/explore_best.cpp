//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

char mp[1005][1005];
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    set<pair<int, int>> s;
    while (t--) {
        int n, m, k, x, y, d;
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> mp[i][j];
        s.clear(); s.insert({x, y});
        int nd = d;
        while (k--) {
            int nx = x + dir[nd][0], ny = y + dir[nd][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == '.') {
                s.insert({nx, ny});
                x = nx, y = ny;
            } else nd = (nd + 1) % 4;
        }
        cout << s.size() << "\n";
    }
    return 0;
}