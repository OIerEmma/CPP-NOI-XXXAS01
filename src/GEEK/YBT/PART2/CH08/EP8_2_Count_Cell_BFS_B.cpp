//
// Created by Geek.Kwok on 2026/3/19.
//
#include <bits/stdc++.h>
using namespace std;

#define N 101
char c[N][N];
int n, m, num, bz[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void doit(int p, int q) {
    int x, y, t, w, i;
    int h[1000][3];
    num++;
    bz[p][q] = 0;
    t = 0; w = 1; h[1][1] = p, h[1][2] = q; // 遇到的第一个细胞入队
    do {
        t++; // 队头指针加1
        for (i = 0; i <= 3; i++) { // 沿细胞的上下左右四个方向搜索
            x = h[t][1] + dx[i]; y = h[t][2] + dy[i];
            // 判断该点是否可以入队
            if ((x >= 0) && (x < m) && (y >= 0) && (y < n) && bz[x][y]) {
                // 搜索到细胞就入队
                w++;
                h[w][1] = x, h[w][2] = y;
                bz[x][y] = 0;
            }
        }

    } while (t < w); // 直至队空为止
}

int main() {
    int i, j;
    char s[100], ch;
    scanf("%d%d\n", &m, &n);
    for (i = 0; i <= m - 1; i++) {
        for (j = 0; j <= n - 1; j++) {
            bz[i][j] = 1; // 初始化
        }
    }
    for (i = 0; i <= m - 1; i++) {
        scanf("%s", s);
        for (j = 0; j <= n - 1; j++) {
            if (s[j] == '0') bz[i][j] = 0;
        }
    }
    for (i = 0; i <= m - 1; i++) {
        for (j = 0; j <= n - 1; j++) {
            if (bz[i][j]) {
                doit(i, j); // 在矩阵中寻找细胞
            }
        }
    }
    printf("NUMBER of cells = %d", num);
    return 0;
}