//
// Created by Amy on 2026/7/6.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double sum = 0;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum += a / 70 * 0.1;
        if (a % 70 != 0) sum += 0.1;
    }
    cout << sum;
    return 0;
}