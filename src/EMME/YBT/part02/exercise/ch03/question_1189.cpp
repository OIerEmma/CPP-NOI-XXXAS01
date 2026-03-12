//
// Created by Emma on 2025/5/30.
//
#include<iostream>
using namespace std;

int p[1000010];

int main() {
    int n;
    scanf("%d", &n);
    p[0] = 1;
    p[1] = 2;
    for (int i = 2; i < 1000000; i++) {
        p[i] = 2 * p[i - 1] + p[i - 2];
        p[i] %= 32767;
    }
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d\n", p[a - 1]);
    }
    return 0;
}
