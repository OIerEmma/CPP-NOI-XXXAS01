//
// Created by Emme.Kwok on 2026/1/2.
//
#include<iostream>
using namespace std;

const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1},
          dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int n, m, x, y;
const int maxn = 301, maxm = 25;
char f[maxm][maxm][maxn];
bool g[maxm][maxm];

void add(char *a, int size_a, char *b, int size_b, char *c, int &size_c) {
    int lenc = 0, x = 0;
    while (lenc < size_a || lenc < size_b) {
        int tmp = (a[lenc] - '0') + (b[lenc] - '0') + x;
        x = tmp / 10;
        c[lenc] = (char) tmp % 10 + '0';
        lenc++;
    }
    c[lenc] = (char) x + '0';
    while (c[lenc] == '0' && lenc > 1) {
        lenc--;
    }
    size_c = lenc + 1;
}

int size_of_ch(char *c) {
    int i;
    for (i = maxn - 1; i >= 0; i --) {
        if (c[i] != '0') break;
    }
    return i + 1;
}

int main() {
    // int size_c;
    // char a[maxn], b[maxn], c[maxn] ;
    // memset(a, '0', sizeof(b));
    // memset(b, '0', sizeof(b));
    // memset(c, '0', sizeof(c));
    // a[0] = '1', a[1] = '2', a[2] = '3';
    // b[0] = '4', b[1] = '5', b[2] = '6';
    // add(a, 3, b, 3, c, size_c);
    // for (int i = 0; i < size_c; i ++) {
    //     cout << c[i] << endl;
    // }
    // cout << size_of_ch(a) << " " << size_of_ch(b) << " " << size_of_ch(c) << endl;
    // return 0;

    cin >> n >> m >> x >> y;
    for (int i = 0; i < maxm; i ++) {
        for (int j = 0; j < maxm; j ++) {
            for (int k = 0; k < maxn; k ++) {
                f[i][j][k] = '0';
            }
        }
    }
    g[x][y] = true;
    for (int i = 0; i < 8; i++) {
        if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
            g[x + dx[i]][y + dy[i]] = true;
        }
    }
    f[0][0][0] = '1';
    for (int k = 1; k <= n; k++) {
        if (!g[k][0]) {
            for (int i = 0; i < maxn; i++) {
                f[k][0][i] = f[k - 1][0][i];
            }
        }
    }
    for (int k = 1; k <= m; k++) {
        if (!g[0][k]) {
            for (int j = 0; j < maxn; j++) {
                f[0][k][j] = f[0][k - 1][j];
            }
        }
    }
    int size_f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!g[i][j]) {
                // cout << strlen(f[i - 1][j]) << endl;
                add(f[i - 1][j], size_of_ch(f[i - 1][j]), f[i][j - 1], size_of_ch(f[i][j - 1]), f[i][j], size_f);
            }
        }
    }
    for (int i = size_f - 1; i >= 0; i--) {
        cout << f[n][m][i];
    }
    return 0;
}