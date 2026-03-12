//
// Created by Emma on 2025/3/2.
//
#include<iostream>
#include<cmath>
using namespace std;

long long TenSystem(int n, int s) {
    int sum = 0, i = 0;
    while (n) {
        sum += n % 10 * int(pow(s, i++));
        n /= 10;
    }
    return sum;
}

void whichSystem(int p, int q, int r) {
    for (int i = 2; i <= 40; i++) {
        if (TenSystem(p, i) * TenSystem(q, i) == TenSystem(r, i)) {
            printf("%d", i);
            return;
        }
    }
    printf("0");
}

int main() {
    int p, q, r;
    cin >> p >> q >> r;
    whichSystem(p, q, r);
    return 0;
}
