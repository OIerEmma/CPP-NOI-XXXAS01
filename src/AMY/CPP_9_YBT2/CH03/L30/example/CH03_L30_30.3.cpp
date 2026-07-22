//
// Created by Amy on 2026/7/9.
//
#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, c;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        switch (a) {
            case 1: cout << b + c << endl; break;
            case 2: cout << b - c << endl; break;
            case 3: cout << b * c << endl; break;
            case 4: cout << b / c << endl; break;
        }
    }
    return 0;
}