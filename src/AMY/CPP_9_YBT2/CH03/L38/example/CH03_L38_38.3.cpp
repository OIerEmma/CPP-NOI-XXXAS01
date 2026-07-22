//
// Created by Amy on 2026/7/17.
//
#include<bits/stdc++.h>
using namespace std;
int n, l, r;
int main() {
    cin >> n;
    l = 1, r = n;
    for (int i = 1; i <= n; i++, l++, r--) {
        for (int j = 1; j <= n; j++) {
            if (j == 1 || j == r) cout << 'X';
            else cout << ' ';
        }
        cout << endl;
    }
    return 0;
}