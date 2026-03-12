//
// Created by Emma on 2025/8/30.
//
#include<iostream>
using namespace std;

const int flag[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[110][110], n, m, ans, xing, q[10010][2];
bool p[110][110], out_flag;

int bfs(int x, int y) {
    int front = 0, rear = 1;
    q[0][0] = x;
    q[0][1] = y;
    while (front < rear) {
        x = q[front][0];
        y = q[front][1];
        front++;
        for (int i = 0; i < 4; i++) {
            int x1 = x + flag[i][0];
            int y1 = y + flag[i][1];
            if (x1 < 1 || y1 < 1 || x1 > 10 || y1 > 10) {
                out_flag = true;
            }
            if (x1 < 1 || y1 < 1 || x1 > 10 || y1 > 10 || a[x1][y1] || p[x1][y1]) {
                continue;
            }
            p[x1][y1] = true;
            q[rear][0] = x1;
            q[rear][1] = y1;
            rear++;
        }
    }
    return front - 1;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (!a[i][j] && !p[i][j]) {
                out_flag = false;
                const int cnt = bfs(i, j);
                if (!out_flag) {
                    ans += cnt;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
