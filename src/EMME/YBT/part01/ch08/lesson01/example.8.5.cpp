//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int a[5], *pa = a;

int main() {
    for (int i = 0; i < 5; i++) {
        scanf("%d", a + i);
        // scanf("%d", pa + i);
        // scanf("%d", a[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("a[%d]=%d\n", i, *(a + i));
        // printf("a[%d]=%d\n", i, *(pa + i));
        // printf("a[%d]=%d\n", i, pa[i]);
        // printf("a[%d]=%d\n", i, a[i]);
    }
    return 0;
}