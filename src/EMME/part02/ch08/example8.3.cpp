//
// Created by Emme.Kwok on 2025/12/14.
//
#include<iostream>
using namespace std;

int dx[12] = {-2, -2, -1, 1, 2, 2, 2, 2, 1, -1, -2, -2},
    dy[12] = {-1, -2, -2, -2, -2, -1, 1, 2, 2, 2, 2, 1};
int s[101][101];
int q[10001][4];

int main() {
    int x1, y1;
    int x2, y2;
    int head = 1, tail = 1;
    q[1][1] = 1;
    q[1][2] = 1;
    q[1][3] = 0;
    memset(s, -1, sizeof(s));
    cin >> x1 >> y1 >> x2 >> y2;
    while (head <= tail) {
        for (int d = 0; d <= 11; d++) {
            int x = q[head][1] + dx[d], y = q[head][2] + dy[d];
            if (x > 0 && y > 0) {
                if (s[x][y] == -1) {
                    s[x][y] = q[head][3] + 1;
                    tail++;
                    q[tail][1] = x;
                    q[tail][2] = y;
                    q[tail][3] = s[x][y];
                    if (s[x1][y1] > 0 && s[x2][y2] > 0) {
                        cout << s[x1][y1] << endl << s[x2][y2] << endl;
                        return 0;
                    }
                }
            }
        }
        head++;
    }
    return 0;
}