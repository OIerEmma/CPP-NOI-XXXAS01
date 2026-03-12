//
// Created by Geek.Kwok on 2026/3/10.
//
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int max_nm = max(n, m), min_nm = min(n, m);
    int max_ab = max(a, b), min_ab = min(a, b);
    int ans = 0;
    for (int i = 0; i <= min_nm / min_ab; i++) {
        int j = (min_nm - i * min_ab) / max_ab;
        if (i * max_ab + j * min_ab <= max_nm) {
            ans = max(ans, i + j);
        }
    }
    cout << ans << endl;
}