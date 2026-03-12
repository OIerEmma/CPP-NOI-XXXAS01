//
// Created by Emma on 2025/8/13.
//
#include<iostream>
using namespace std;

char a1[201], b1[201];
int a[201], b[201], c[40001];

int main() {
    cin >> a1 >> b1;
    int lena = (int)strlen(a1), lenb = (int)strlen(b1);
    for (int i = 0; i < lena; i++) {
        a[lena - i] = a1[i] - 48;
    }
    for (int i = 0; i < lenb; i++) {
        b[lenb - i] = b1[i] - 48;
    }
    int x;
    for (int i = 1; i <= lena; i++) {
        x = 0;
        for (int j = 1; j <= lenb; j++) {
            c[i + j - 1] += a[i] * b[j] + x;
            x = c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
        c[i + lenb] = x;
    }
    int lenc = lena + lenb;
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    for (int i = lenc; i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}