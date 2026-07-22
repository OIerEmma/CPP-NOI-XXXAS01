//
// Created by Amy on 2026/7/9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> d;
        if (d - c == c - b && c - b == b - a) cout << a << " " << b << " " << c << " " << d << " " << d + (d - c);
        else cout << a << " " << b << " " << c << " " << d << " " << d * (d / c);
        cout << endl;
    }
    return 0;
}
