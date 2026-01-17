//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n, m;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        if (m > n) {
            cout << 0 << endl;
            continue;
        }
        if (m == 0 || m == n) {
            cout << 1 << endl;
            continue;
        }
        if (m * 2 > n) {
            m = n - m;
        }
        long long ans = 1;
        for (int j = n; j >= n - m + 1; j--) {
            ans *= j;
        }
        long long fac = 1;
        for (int j = 2; j <= m; j++) {
            fac *= j;
        }
        ans /= fac;
        cout << ans << endl;
    }
    return 0;
}