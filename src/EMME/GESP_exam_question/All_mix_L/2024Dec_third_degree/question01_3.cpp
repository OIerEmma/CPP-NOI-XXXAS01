//
// Created by Emma on 2025/2/8.
//
#include <iostream>
using namespace std;

int main() {
    int n, k, A[100001], maxvalue = -1, minvalue = 100001;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        maxvalue = max(maxvalue, A[i]);
        minvalue = min(minvalue, A[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (A[i] > k) {
            A[i] = maxvalue;
        } else if (A[i] < k) {
            A[i] = minvalue;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}