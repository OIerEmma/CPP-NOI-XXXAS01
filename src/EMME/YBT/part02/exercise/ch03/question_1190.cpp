//
// Created by Emma on 2025/5/30.
//
#include<iostream>
using namespace std;

long long f[75];

int main() {
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i = 4; i < 71; i++) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
    int a;
    for (; ;) {
        scanf("%d", &a);
        if (a == 0) {
            break;
        }
        printf("%lld\n", f[a]);
    }
    return 0;
}
