//
// Created by Amy on 2026/7/22.
//
#include<bits/stdc++.h>
using namespace std;

int n, m, x, cf;

int main() {
    scanf("%d %d %d", &m, &n, &x);
    cf = n;
    while (cf <= m && x) {
        x -= ceil(double (m) / cf);
        if (x < 0)
            break;
        cf += floor(double (m) / cf);
    }
    printf("%d", cf);
    return 0;
}