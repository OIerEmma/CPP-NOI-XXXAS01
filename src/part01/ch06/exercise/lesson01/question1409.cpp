//
// Created by Emma on 2025/2/23.
//
#include<iostream>
#include<cmath>
bool isprime(int x) {
    if (x == 1 || x == 0) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x, y, cnt = 0;
    scanf("%d %d", &x, &y);
    for (int i = x; i <= y; i++) {
        if (isprime(i)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
}