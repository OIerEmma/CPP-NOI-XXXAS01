//
// Created by Emma on 2025/8/12.
//
#include<iostream>
using namespace std;

int a1[201], b1[201], c[301];
char a[201], b[201];

int main() {
    cin >> a >> b;
    for (int i = 1; i <= strlen(a); i++) {
        a1[i] = a[strlen(a) - i] - '0';
    }
    for (int i = 1; i <= strlen(b); i++) {
        b1[i] = b[strlen(b) - i] - '0';
    }
    int lenc = 1, x = 0;
    while (lenc <= strlen(a) || lenc <= strlen(b)) {
        c[lenc] = a1[lenc] + b1[lenc] + x;
        x = c[lenc] / 10;
        c[lenc] %= 10;
        lenc++;
    }
    c[lenc] = x;
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    for (int i = lenc; i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
