//
// Created by Emma on 2025/8/14.
//
#include<iostream>
#include<cstring>
using namespace std;

int a[1000001];

int main() {
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        a[0] = 1;
        int lena = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < lena; j++) {
                a[j] *= i;
            }
            for (int j = 0; j < lena; j++) {
                a[j + 1] += a[j] / 10;
                if (j == lena - 1 && a[j] >= 10) {
                    lena++;
                }
                a[j] %= 10;
            }
        }
        for (int i = lena - 1; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
