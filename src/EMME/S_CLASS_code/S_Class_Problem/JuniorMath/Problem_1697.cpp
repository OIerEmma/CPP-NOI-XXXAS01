//
// Created by Emme.Kwok on 2025/9/19.
//
#include<iostream>
using namespace std;

bool fab(int a, int b, int c, int d, int e) {
    if (a + b == c && b + c == d && c + d == e) {
        return true;
    }
    return false;
}

bool samecha(int a, int b, int c, int d, int e) {
    int cha = b - a;
    if (cha == 0) {
        return false;
    }
    if (c - b == cha && d - c == cha && e - d == cha) {
        return true;
    }
    return false;
}

int main() {
    int a, b, c, d, e;
    while (cin >> a) {
        cin >> b >> c >> d >> e;
        if (a == 0 && b == 0 && c == 0 && d == 0 && d == 0) {
            break;
        }
        if (fab(a, b, c, d, e)) {
            cout << d + e << " ";
            cout << e + d + e << " ";
            cout << d + e + e + d + e << " ";
            cout << e + d + e + d + e + e + d + e << " ";
            cout << d + e + e + d + e + e + d + e + d + e + e + d + e << " ";
        } else if (samecha(a, b, c, d, e)) {
            int cha = b - a;
            cout << e + cha << " ";
            cout << e + cha + cha << " ";
            cout << e + cha + cha + cha << " ";
            cout << e + cha + cha + cha + cha << " ";
            cout << e + cha + cha + cha + cha + cha << endl;
        } else {
            int bei = b / a;
            cout << e * bei << " ";
            cout << e * bei * bei << " ";
            cout << e * bei * bei * bei << " ";
            cout << e * bei * bei * bei * bei << " ";
            cout << e * bei * bei * bei * bei * bei << endl;
        }
    }
    return 0;
}