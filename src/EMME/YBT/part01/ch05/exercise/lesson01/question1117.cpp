//
// Created by Emma on 2025/1/19.
//
#include <iostream>
using namespace std;
#define N 20020
int main() {
    int n, i, b, a[N];
    scanf("%d", &n);
    memset(a ,0, sizeof(a));
    for (i = 1; i <= n; i++){
        scanf("%d", &b);
        if (!a[b]) {
            a[b] = i;
            cout << b << " ";
        }
    }
    return 0;
}
