//
// Created by Emma on 2025/5/30.
//
#include<iostream>
using namespace std;

long long a[10010], b[10010];

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    for (int i = 0; i < x; i++) {
        a[i] = 1;
    }
    for (int i = x; i <= z; i++) {
        b[i] = a[i - x] * y;
        a[i] = a[i - 1] + b[i - 2];
    }
    printf("%lld\n", a[z]);
    return 0;
}