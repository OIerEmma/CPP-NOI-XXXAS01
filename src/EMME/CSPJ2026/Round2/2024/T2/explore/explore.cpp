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
        s.clear();
        s.insert({x, y});
        int nd = d;
        // bool flag = false;
        for (int i = 1; i <= k; i++) {
            int nx = x + dir[nd][0], ny = y + dir[nd][1];
            while (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x') {
                nd = (nd + 1) % 4;
                nx = x + dir[nd][0], ny = y + dir[nd][1];
                // cout << "turn\n";
                i++;
                if (i > k) break;
                // if (s.count({nx, ny})) { flag = true; break; }
            }
            if (i > k) break;
            x = nx, y = ny;
            s.insert({x, y});
            // cout << "dir:" << nd << " x:" << nx << " y:" << ny << endl;
        }
        // for (auto p : s) cout << p.first << " " << p.second << endl;
        cout << s.size() << "\n";
    }
    return 0;
}
/*
2
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
5 5 100
5 4 1
...xx
.xxx.
..x..
xxx..
xx..x
d=0代表向东，
d=1代表向南，
d=2代表向西，
d=3代表向北
*/