//
// Created by Emma on 2025/7/13.
//
#include<iostream>
using namespace std;

int f(int m, int y) {
    if (m == 2) {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
            return 29;
        }
        return 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

int main() {
    int m, n;
    while (cin >> m && cin >> n) {
        if (m < 10) {
            cout << "000";
        } else if (m < 100) {
            cout << "00";
        } else if (m < 1000) {
            cout << "0";
        }
        cout << m << "-";
        int t = 1, ans = 0;
        while (n >= 28) {
            n -= f(t % 12, m);
            ans++;
            t++;
        }
        if (n <= 0) {
            ans--;
            n += f(t % 12 - 1, m);
        } else if (t >= 13) {
            ans--;
        }
        if (ans + 1 < 10) {
            cout << "0" << ans + 1;
        } else {
            cout << ans + 1;
        }
        cout << "-";
        if (n < 10) {
            cout << "0" << n << endl;
        } else {
            cout << n << endl;
        }
    }
    return 0;
}
