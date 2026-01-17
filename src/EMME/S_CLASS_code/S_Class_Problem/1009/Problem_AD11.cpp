//
// Created by Emma on 2025/7/31.
//
#include<iostream>
using namespace std;

bool leapery(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int day_num(int m, int y) {
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    if (m == 2) {
        if (leapery(y)) {
            return 29;
        }
        return 28;
    }
    return 31;
}

int main() {
    int t, y, m, d, add;
    cin >> t;
    for (int s = 1; s <= t; s++) {
        cin >> y >> m >> d >> add;
        d += add;
        string str1 = "-", str2 = "-";
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            while (d > 30) {
                d -= day_num(m, y);
                m++;
                if (m > 12) {
                    y++;
                    m -= 12;
                }
            }
            if (m > 12) {
                y += m / 12;
                m %= 12;
            }
        } else if (m == 2) {
            int a;
            if (leapery(y)) {
                a = 29;
            } else {
                a = 28;
            }
            while (d > a) {
                d -= day_num(m, y);
                m++;
                if (m > 12) {
                    y++;
                    m -= 12;
                }
            }
            if (m > 12) {
                y += m / 12;
                m %= 12;
            }
        } else {
            while (d > 31) {
                d -= day_num(m, y);
                m++;
                if (m > 12) {
                    y++;
                    m -= 12;
                }
            }
            if (m > 12) {
                y += m / 12;
                m %= 12;
            }
        }
        if (m < 10) {
            str1 = "-0";
        }
        if (d < 10) {
            str2 = "-0";
        }
        cout << y << str1 << m << str2 << d << endl;
    }
    return 0;
}
