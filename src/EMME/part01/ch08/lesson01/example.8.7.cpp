//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

const int len = 100001;
int x[len], y[len], d[len];
int c[len], *a[len];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d %d", &x[i], &y[i], &d[i]);
        c[y[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        a[i] = new int[c[i]];
    }
    for (int i = 1; i <= k; i++) {
        *a[y[i]] = d[i];
        a[y[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        a[i] -= c[i];
        for (int j = 1; j <= c[i]; j++, a[i]++) {
            printf("%d ", *a[i]);
        }
    }
    return 0;
}