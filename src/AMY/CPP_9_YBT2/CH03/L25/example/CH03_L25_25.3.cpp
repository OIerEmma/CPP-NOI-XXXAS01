//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int n, sum1, sum2, i;
int main() {
    cin >> n;
    for (i = 2; i <= n; i += 2) {
        sum1 += i;
    }
    i = 1;
    while (i <= n) {
        sum2 += i;
        i += 2;
    }
    cout << sum1 << ' ' << sum2;
        return 0;
}
