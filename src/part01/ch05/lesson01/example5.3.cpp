//
// Created by Emma on 2025/1/12.
//
#include<iostream>
#include<cstring>
#define MAXN 1000
int a[MAXN];
using namespace std;

int main() {
    int n, first = 1;
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % i == 0) {
                a[j] = !a[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            if (first) {
                first = 0;
            } else {
                printf(" ");
            }
            cout << i;
        }
    }
    return 0;
}
