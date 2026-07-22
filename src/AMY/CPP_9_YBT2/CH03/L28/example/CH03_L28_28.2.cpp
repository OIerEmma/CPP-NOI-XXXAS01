//
// Created by Amy on 2026/7/1.
//
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    double e = 1, jc = 1;
    for (int i = 1; i <= n; i++) {
        jc *= i;
        e = e + 1 / jc;
    }
    printf("%.10lf",e);
    return 0;
}
