//
// Created by Amy on 2026/7/8.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1, base = 92;
    while (n > 0) {
        if (n & 1) ans = ans * base % 100;
        base = base * base % 100;
        n >>= 1;
    }
    printf("%02d\n", ans);
    return 0;
}