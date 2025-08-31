//
// Created by Emma on 2025/8/30.
//
#include<iostream>
using namespace std;

const int flag[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[110][110], queue[10010][2], n, m, ans;
bool p[110][110];

void bfs(int x, int y) {
    int front = 0, rear = 2;
    queue[1][0] = x;
    queue[1][1] = y;
    while (front < rear - 1) {
        front++;
        x = queue[front][0];
        y = queue[front][1];
        for (int i = 0; i < 4; i++) {
            int x1 = x + flag[i][0];
            int y1 = y + flag[i][1];
            if (x1 < 1 || y1 < 1 || x1 > n || y1 > m || !a[x1][y1] || p[x1][y1]) {
                continue;
            }
            p[x1][y1] = true;
            queue[rear][0] = x1;
            queue[rear++][1] = y1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] && !p[i][j]) {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
