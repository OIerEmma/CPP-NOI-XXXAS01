//
// Created by Emma on 2025/7/30.
//
#include<iostream>
using namespace std;

bool leapery(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main() {
    int t, y, m, d;
    cin >> t;
    for (int s = 1; s <= t; s++) {
        cin >> y >> m >> d;
        string str1 = "-", str2 = "-";
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d + 1 <= 30) {
                if (m < 10) {
                    str1 = "-0";
                }
                if (d + 1 < 10) {
                    str2 = "-0";
                }
                cout << y << str1 << m << str2 << d + 1 << endl;
            } else {
                if (m + 1 < 10) {
                    str1 = "-0";
                }
                cout << y << str1 << m + 1 << "-0" << 1 << endl;
            }
        } else if (m == 2) {
            int a;
            if (leapery(y)) {
                a = 29;
            } else {
                a = 28;
            }
            if (d + 1 < 10) {
                str2 = "-0";
            }
            if (d + 1 <= a) {
                cout << y << "-0" << 2 << str2 << d + 1 << endl;
            } else {
                cout << y << "-0" << 3 << "-0" << 1 << endl;
            }
        } else if (m == 12) {
            if (d + 1 <= 9) {
                str2 = "-0";
            }
            if (d + 1 <= 31) {
                cout << y << "-" << 12 << str2 << d + 1 << endl;
            } else {
                cout << y + 1 << "-0" << 1 << "-0" << 1 << endl;
            }
        } else {
            if (m < 10) {
                str1 = "-0";
            }
            if (d + 1 < 10) {
                str2 = "-0";
            }
            if (d + 1 <= 31) {
                cout << y << str1 << m << str2 << d + 1 << endl;
            } else {
                cout << y << str1 << m + 1 << "-0" << 1 << endl;
            }
        }
    }
    return 0;
}
