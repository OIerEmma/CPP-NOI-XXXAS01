//
// Created by Amy on 2026/7/17.
//
#include<bits/stdc++.h>
using namespace std;
int n, m, b;
char c;
int main() {
    cin >> n >> m >> c >> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 || j == 1 || i == n || j == m) cout << c;
            else
                if (b == 1) cout << c; else cout << ' ';
        }
        cout << endl;
    }
    return 0;
}