//
// Created by Geek.Kwok on 3/20/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 1001

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, cnt, g[N * N], vis[N][N], bs, minx, miny, maxx, maxy;
char mp[N][N];

void dfs(int x, int y) {
    minx = min(minx, x), maxx = max(maxx, x);
    miny = min(miny, y), maxy = max(maxy, y);
    bs = (maxx - minx + 1) * (maxy - miny + 1);
    vis[x][y] = cnt;
    g[cnt]++;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || mp[xx][yy] == '.') continue;
        dfs(xx, yy);
    }
}

int main() {
    cin >> n >> m;
    // 成功：全过
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    // 失败：错了6个
    // 猜测：测试样例中有些输入可能每行后面含有空格等字符
    // getchar();
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         scanf("%c", &mp[i][j]);
    //     }
    //     getchar();
    // }
    // 样例1的打印输出正常
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         printf("%c", mp[i][j]);
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && mp[i][j] == '#') {
                cnt++;
                vis[i][j] = cnt;
                minx = n + 1, maxx = 0, miny = m + 1, maxy = 0;
                dfs(i, j);
                if (g[cnt] != bs) {
                    cout << "Bad placement." << endl;
                    exit(0);
                }
            }
        }
    }
    cout << "There are " << cnt << " ships." << endl;
    return 0;
}