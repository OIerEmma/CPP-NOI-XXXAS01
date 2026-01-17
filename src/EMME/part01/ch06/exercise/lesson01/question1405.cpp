//
// Created by Emma on 2025/2/23.
//
#include<iostream>
using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int s, maxn = -1;
    scanf("%d", &s);
    for (int i = 2; i <= s / 2; i++) {
        if (isPrime(i) && isPrime(s - i)) {
            maxn = max(maxn, i * (s - i));
        }
    }
    printf("%d\n", maxn);
    return 0;
}
