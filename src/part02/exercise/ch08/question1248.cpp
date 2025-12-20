//
// Created by Emme.Kwok on 2025/12/14.
//
#include<iostream>
using namespace std;

struct node {
    int l, x, y;
};
char a[100][100][100];
bool f[100][100][100];
int step[100][100][100];
int dl[] = {-1, 1, 0, 0, 0, 0},
    dx[] = {0, 0, -1, 1, 0, 0},
    dy[] = {0, 0, 0, 0, -1, 1};
node start, endn;
int s, n, m;

int bfs() {
    queue<node> q;
    q.push(start);
    f[start.l][start.x][start.y] = true;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.l == endn.l && now.x == endn.x && now.y == endn.y) {
            return step[now.l][now.x][now.y];
        }
        for (int d = 0; d <= 5; d++) {
            int l = now.l + dl[d];
            int x = now.x + dx[d];
            int y = now.y + dy[d];
            if (l >= 1 && l <= s && x >= 1 && x <= n && y >= 1 && y <= m && (a[l][x][y] == '.' || a[l][x][y] == 'E') && !f[l][x][y]) {
                node t;
                t.l = l;
                t.x = x;
                t.y = y;
                q.push(t);
                f[l][x][y] = true;
                step[l][x][y] = step[now.l][now.x][now.y] + 1;
            }
        }
    }
    return -1;
}

// void print() {
//     for (int i = 1; i <= s; i++) {
//         for (int j = 1; j <= n; j++) {
//             for (int k = 1; k <= m; k++) {
//                 cout << a[i][j][k];
//             }
//             cout << endl;
//         }
//     }
// }

int main() {
    while(cin >> s) {
        cin >> n >> m;
        if (s == 0 && n == 0 && m == 0) {
            break;
        }
        memset(f, false, sizeof(f));
        memset(step, 0, sizeof(step));
        for (int i = 1; i <= s; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S') {
                        start.l = i;
                        start.x = j;
                        start.y = k;
                    }
                    if (a[i][j][k] == 'E') {
                        endn.l = i;
                        endn.x = j;
                        endn.y = k;
                    }
                }
                getchar();
            }
        }
        // print();
        int temp = bfs();
        if (temp == -1) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << temp << " minute(s)." << endl;
        }
    }
    return 0;
}