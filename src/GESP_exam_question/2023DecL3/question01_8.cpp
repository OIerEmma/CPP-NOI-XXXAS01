//
// Created by Emma on 2025/3/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, i;
    scanf("%d\n%d", &n, &i);
    int x, b;
    for (int a = 1; ; a++) {
        x = n * a + i;
        for (b = n - 1; b >= 1; b--) {
            if (x * n % (n - 1) == 0) {
                x = x * n / (n - 1) + i;
            } else {
                break;
            }
        }
        if (b == 0) {
            break;
        }
    }
    printf("%d\n", x);
    return 0;
}
