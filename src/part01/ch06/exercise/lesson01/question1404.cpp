//
// Created by Emma on 2025/2/23.
//
#include<iostream>
using namespace std;

int main() {
    int s, n, i;
    scanf("%d", &n);
    for (i = 1; ; i++) {
        s = i * (i + 1) / 2;
        s -= n;
        if (s % 3 == 0 && s >= 0) {
            break;
        }
    }
    printf("%d %d", s / 3, i);
    return 0;
}
