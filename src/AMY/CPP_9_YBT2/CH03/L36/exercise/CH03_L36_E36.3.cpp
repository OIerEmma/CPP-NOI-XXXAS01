//
// Created by Amy on 2026/7/15.
//
#include <cstdio>

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d*%d=%2d", i, j, i * j);
            if (j < i) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}
