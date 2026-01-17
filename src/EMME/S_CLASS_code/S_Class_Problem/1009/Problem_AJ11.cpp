//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int x[1010];

int main() {
    int n;
    while(cin >> n) {
        int a = 0, b = 0, c = 0, e = -1, d_t = 0, ch = -1;
        double d = 0.0;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            if (x[i] % 5 == 0 && x[i] % 2 == 0) {
                a += x[i];
            } else if (x[i] % 5 == 1) {
                b += x[i] * ch;
                flag = true;
                ch = -ch;
            } else if (x[i] % 5 == 2) {
                c++;
            } else if (x[i] % 5 == 3) {
                d += x[i];
                d_t++;
            } else if (x[i] % 5 == 4) {
                e = max(e, x[i]);
            }
        }
        b = -b;
        if (d_t != 0) {
            d /= d_t;
        } else {
            d = 0.0;
        }
        if (a == 0) {
            cout << "N ";
        } else {
            cout << a << " ";
        }
        if (flag) {
            cout << b << " ";
        } else {
            cout << "N ";
        }
        if (c == 0) {
            cout << "N ";
        } else {
            cout << c << " ";
        }
        if (d == 0) {
            cout << "N ";
        } else {
            printf("%.1lf ", d);
        }
        if (e == -1) {
            cout << "N" << endl;
        } else {
            cout << e << endl;
        }
    }
    return 0;
}