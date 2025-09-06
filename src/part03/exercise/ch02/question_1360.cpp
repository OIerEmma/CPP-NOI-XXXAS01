//
// Created by Emma on 2025/9/6.
//
#include<iostream>
using namespace std;

const int flag[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool p[210];
int q[210], l[210], n, a, b;

int bfs(int x) {
    int front = 0, rear = 1;
    q[0] = x;
    int cnt = 0, f = 1;
    while (front < rear) {
        if (f == b) {
            break;
        }
        cnt++;
        x = q[front][0];
        front++;
        for (int i = 0; i < 4; i++) {
            int x1 = x + flag[i][0];
            int y1 = y + flag[i][1];
            if (x1 < 1 || x1 > 10 || y1 > 10) {
                out_flag = true;
            }
            if (x1 < 1 || y1 < 1 || x1 > 10 || y1 > 10 || p[x1][y1]) {
                continue;
            }
            p[x1] = true;
            q[rear] = x1;
            q[rear] = y1;
            rear++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    cout << bfs() << endl;
    return 0;
}