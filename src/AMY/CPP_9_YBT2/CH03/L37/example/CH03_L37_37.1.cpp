//
// Created by Amy on 2026/7/16.
//
#include<bits/stdc++.h>
using namespace std;
int n, t;
double sum;
int main() {
    cin >> n;
    for (int i = 1, f = 1; i <= n; i++, f *= -1)
        sum += 1.0 * f / i;
    printf("%.4lf",sum);
    return 0;
}
