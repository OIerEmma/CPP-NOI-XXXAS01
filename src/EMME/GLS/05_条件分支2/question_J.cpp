//
// Created by Emme.Kwok on 2026/1/9.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m = max(a, max(b, max(c, d)));
    int x, y, z;
    if (m == a) {
        x = m - b, y = m - c, z = m - d;
    } else if (m == b) {
        x = m - a, y = m - c, z = m - d;
    } else if (m == c) {
        x = m - a, y = m - b, z = m - d;
    } else {
        x = m - a, y = m - b, z = m - c;
    }
    if (x > y) {
        swap(x, y);
    }
    if (x > z) {
        swap(x, z);
    }
    if (y > z) {
        swap(y, z);
    }
    cout << x << " " << y << " " << z;
    return 0;
}