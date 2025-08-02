//
// Created by Emma on 2025/2/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, a, b, t;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d\n", &n, &a, &b);
        printf("%d\n", n - max(n - b, a + 1) + 1);
    }
    return 0;
}