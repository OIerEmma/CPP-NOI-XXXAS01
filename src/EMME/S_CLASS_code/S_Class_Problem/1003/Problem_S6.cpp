//
// Created by Emma on 2025/7/2.
//
#include <cstdio>
#include <iostream>
using namespace std;

int idx[10010], a[10010];

int main() {
    int n;
    cin >> n;
    a[0] = n;
    int maxx = a[0];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) {
            maxx = a[i];
        } else {
            if (a[i] > maxx) {
                maxx = a[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        idx[a[i]]++;
    }
    for (int i = 0; i <= maxx; i++) {
        printf("%d\n", idx[i]);
    }
    return 0;
}
