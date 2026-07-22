//
// Created by Amy on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;
double a, b, c, temp;
int main() {
    cin >> a >> b >> c;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b < c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
