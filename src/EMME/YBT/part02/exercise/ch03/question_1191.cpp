//
// Created by Emma on 2025/5/30.
//
#include<iostream>
using namespace std;

char c[110][110];

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    scanf("%d", &m);
    for (int x = 1; x < m; x++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] == '@') {
                    if (c[i - 1][j] == '.') {
                        c[i - 1][j] = '$';
                    }
                    if (c[i + 1][j] == '.') {
                        c[i + 1][j] = '$';
                    }
                    if (c[i][j + 1] == '.') {
                        c[i][j + 1] = '$';
                    }
                    if (c[i][j - 1] == '.') {
                        c[i][j - 1] = '$';
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (c[i][j] == '$') {
                    c[i][j] = '@';
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == '@') {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}