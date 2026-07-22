//
// Created by Amy on 2026/7/15.
//
#include<bits/stdc++.h>
using namespace std;
int n, x, q = 0, sum = 0;
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        q = i;
        while (q > 0) {
            if (q % 10 == x) sum++;
            q /= 10;
        }
    }
    cout << sum;
    return 0;
}