//
// Created by Emma on 2025/8/14.
//
#include<iostream>
#include<cstring>
using namespace std;

int a1[1001], b1[1001], c[1001];
char a[1001], b[1001];

int main() {
    while(cin >> a) {
        cin >> b;
        memset(a1, 0, sizeof(a1));
        memset(b1, 0, sizeof(b1));
        memset(c, 0, sizeof(c));
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
    }
    return 0;
}
