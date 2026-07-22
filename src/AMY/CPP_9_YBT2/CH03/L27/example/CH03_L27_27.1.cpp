//
// Created by Amy on 2026/6/30.
//
#include<bits/stdc++.h>
using namespace std;
int n, x, sum;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
    }
    printf("%d %.5lf", sum, 1.0 * sum / n);
    return 0;
}
