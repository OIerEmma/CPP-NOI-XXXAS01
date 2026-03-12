//
// Created by Emme.Kwok on 2026/1/17.
//
#include<iostream>
#include<cmath>
using namespace std;

int a[20][20], cnt[256], color[16], cmp[20][20];
int n, m;

int tran(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

char tranc(int n) {
    if (n < 10) {
        return (char)(n + 48);
    }
    return (char)('A' + (n - 10));
}

int compress(int o) {
    int minv = 513, mini = -1;
    for (int i = 0; i < 16; i++) {
        if (abs(o - color[i]) < minv) {
            minv = abs(o - color[i]);
            mini = i;
        }
    }
    return mini;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char line[50];
        cin >> line;
        m = (int)strlen(line) / 2;
        for (int j = 0; j < m; j++) {
            a[i][j] = tran(line[2 * j]) * 16 + tran(line[2 * j + 1]);
            cnt[a[i][j]]++;
        }
    }
    for (int i = 0; i < 16; i++) {
        int maxv = -1, maxc = -1;
        for (int j = 0; j < 256; j++) {
            if (cnt[j] > maxc) {
                maxc = cnt[j];
                maxv = j;
            }
        }
        color[i] = maxv;
        cnt[maxv] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cmp[i][j] = compress(a[i][j]);
        }
    }
    for (int i = 0; i < 16; i++) {
        cout << tranc(color[i] / 16) << tranc(color[i] % 16);
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tranc(cmp[i][j]);
        }
        cout << endl;
    }
    return 0;
}