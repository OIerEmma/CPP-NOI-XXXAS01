//
// Created by Emma on 2025/7/3.
//
#include <iostream>
using namespace std;

int a[110][110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
