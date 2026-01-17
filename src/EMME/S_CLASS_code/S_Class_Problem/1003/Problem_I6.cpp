//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

int a[110][110], b[110][110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == b[i][j]) {
                ans++;
            }
        }
    }
    printf("%.2lf", (ans * 1.0 / (n * m)) * 100);
    return 0;
}