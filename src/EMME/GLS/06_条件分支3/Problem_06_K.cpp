//
// Created by Emme.Kwok on 2026/3/14.
//
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = max(a, b), d = 7 - c, e = 6;
    if (d == 2) {
        d = 1;
        e = 3;
    } else if (d == 3) {
        d = 1;
        e = 2;
    } else if (d == 6) {
        d = 1;
        e = 1;
    } else if (d == 4) {
        d = 2;
        e = 3;
    }
    cout << d << '/' << e << endl;
    return 0;
}