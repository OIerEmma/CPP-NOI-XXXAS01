//
// Created by Emma on 2025/2/9.
//
#include <iostream>
using namespace std;

int main() {
    int n, L, x[1000001], d[1000001], maxvalue = -1, minvalue = 1000001;
    scanf("%d %d\n", &n, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &d[i]);
        if (d[i] == 0) {
            maxvalue = max(maxvalue, x[i]);
        } else {
            minvalue = min(minvalue, x[i]);
        }
    }
    maxvalue = max(maxvalue, L - minvalue);
    printf("%d\n", maxvalue);
    return 0;
}