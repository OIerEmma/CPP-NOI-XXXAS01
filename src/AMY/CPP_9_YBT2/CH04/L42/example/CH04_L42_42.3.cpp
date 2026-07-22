//
// Created by Amy on 2026/7/22.
//
#include<bits/stdc++.h>
using namespace std;

double a, b;

int main() {
    cin >> a >> b;
    if (fabs(a - b) < 1e-8) cout << "yes";
    else cout << "no";
    return 0;
}