//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
double n, a, sum;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum += a;
    }
    printf("%.2lf",sum / n);
    return 0;
}
