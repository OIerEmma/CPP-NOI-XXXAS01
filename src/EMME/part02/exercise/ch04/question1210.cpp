//
// Created by Emma on 2025/4/4.
//
#include<iostream>
#include<cstring>
using namespace std;
int a[1000];

void factor(int n, int i) {
    if (n <= 1) {
        return;
    }
    if (n % i == 0) {
        a[i]++;
        factor(n / i, i);
    } else {
        factor(n, i + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    bool isfirst = true;
    memset(a, 0, sizeof(a));
    factor(n, 2);
    for (int i = 0; i < 1000; i++) {
        if (a[i] >= 1) {
            if (isfirst) {
                isfirst = false;
            } else {
                printf("*");
            }
            if (a[i] >= 2) {
                printf("%d^%d", i, a[i]);
            } else {
                printf("%d", i);
            }
        }
    }
    printf("\n");
    return 0;
}
