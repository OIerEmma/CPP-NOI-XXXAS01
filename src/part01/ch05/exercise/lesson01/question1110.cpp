//
// Created by Emma on 2025/1/19.
//
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k, flag = 0;
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            flag++;
            printf("%d", i + 1);
            break;
        }
    }
    if (flag == 0) printf("-1");
    return 0;
}
