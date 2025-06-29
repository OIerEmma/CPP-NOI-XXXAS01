//
// Created by Emma on 2024/1/1.
//
#include<iostream>
using namespace std;

int a[10010];

int main() {
    int n;
    scanf("%d", &n);
    a[0] = 1;
    a[1] = 1;
    printf("x[0]=1\nx[1]=1\n");
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
        printf("x[%d]=%d\n", i, a[i]);
    }
    return 0;
}