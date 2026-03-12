//
// Created by Emma on 2025/8/13.
//
#include<iostream>
using namespace std;

char a1[101];
int a[101], c[101];

int main() {
    cin >> a1;
    int lena = (int)strlen(a1);
    for (int i = 0; i < lena; i++) {
        a[i + 1] = a1[i] - 48;
    }
    int x = 0;
    for (int i = 1; i <= lena; i++) {
        c[i] = (x * 10 + a[i]) / 13;
        x = (x * 10 + a[i]) % 13;
    }
    int lenc = 1;
    while (c[lenc] == 0 && lenc < lena) {
        lenc++;
    }
    for (int i = lenc; i <= lena; i++) {
        cout << c[i];
    }
    cout << endl << x << endl;
    return 0;
}