//
// Created by Emme.Kwok on 2026/9/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, x;
    cin >> a >> b;
    cout << a << "/" << b << "=";
    if (b % a == 0) {
        cout << "1/" << b / a;
    } else {
        while (a != 1) {
            x = b / a + 1;
            a = a * x - b;
            b *= x;
            if (b % a == 0) {
                b /= a;
                a = 1;
            }
            cout << "1/" << x << "+";
        }
        cout << "1/" << b;
    }
    return 0;
}