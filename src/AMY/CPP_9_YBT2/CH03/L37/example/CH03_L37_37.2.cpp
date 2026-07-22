//
// Created by Amy on 2026/7/16.
//
#include<bits/stdc++.h>
using namespace std;
int n, t;
double sum;
int main() {
    cin >> n;
    for (int i = 1, q = 2, p = 1; i <= n; i++, t = q, q += p, p = t)
        sum += 1.0 * q / p;
    printf("%.4lf",sum);
    return 0;
}
