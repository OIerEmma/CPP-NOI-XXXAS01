//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

int b[101];

int main() {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        b[k]++;
    }
    for (int i = 0; i <= 100; i++) {
        while(b[i] > 0) {
            printf("%d ", i);
            b[i]--;
        }
    }
    printf("\n");
    return 0;
}