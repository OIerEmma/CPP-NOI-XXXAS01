//
// Created by Emma on 2025/4/6.
//
//
// Created by Emma on 2025/4/4.
//
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}
