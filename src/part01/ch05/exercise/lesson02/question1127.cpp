//
// Created by Emma on 2025/2/7.
//
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, m, a[100][100];
    scanf("%d %d", &n, &m);
    memset(a, 0, sizeof(a));
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
