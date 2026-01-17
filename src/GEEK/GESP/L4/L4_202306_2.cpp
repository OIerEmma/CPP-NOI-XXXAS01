//
// Created by Geek.Kwok on 2026/1/17.
//
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 20;
int his[maxn][maxn], N, M, cnt[256], color[16], cmp[maxn][maxn];

int trani(char c) {
    // 0..9ABCDEF
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

char tranc(int n) {
    if (n < 10) {
        return (char) (n + 48);
    }
    return 'A' + n - 10;
}

int compress(int o) {
    // find out closest pixel
    int minv = 513, mini = -1;
    for (int i = 0; i < 16; i++) {
        if (minv > abs(o - color[i])) {
            minv = abs(o - color[i]);
            mini = i;
        }
    }
    return mini;
}

int main() {
    // 1.input
    cin >> N;
    for (int i = 0; i < N; i++) {
        char line[50];
        cin >> line;
        M = (int) strlen(line) / 2;
        for (int j = 0; j < M; j++) {
            // "ABAFAC"
            // AB -> 233
            his[i][j] = trani(line[2*j]) * 16 + trani(line[2*j+1]);
            cnt[his[i][j]]++;
        }
    }
    // 2. find out 16 colors
    for (int i = 0; i < 16; i++) {
        int maxv = -1, maxc = -1;
        for (int j = 0; j < 256; j++) {
            if (maxc < cnt[j]) {
                maxc = cnt[j];
                maxv = j;
            }
        }
        color[i] = maxv;
        cnt[maxv] = -1;
    }
    // 3. compress
    for (int i = 0; i < N; i++) {
        for (int j  = 0; j < M; j++) {
            cmp[i][j] = compress(his[i][j]);
        }
    }
    // final: part1, part2
    for (int i = 0; i < 16; i++) {
        cout << tranc(color[i] / 16) << tranc(color[i] % 16);
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j =0; j < M; j++) {
            cout << tranc(cmp[i][j]);
        }
        cout << endl;
    }
    return 0;
}