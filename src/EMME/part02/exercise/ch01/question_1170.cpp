//
// Created by Emma on 2025/8/12.
//
#include<iostream>
using namespace std;

int a[1001];

int main() {
    int n, lena = 1;
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < lena; j++) {
            a[j] *= 2;
        }
        for (int j = 0; j < lena; j++) {
            if (a[j] > 9) {
                a[j + 1]++;
                a[j] -= 10;
                if (j == lena - 1) {
                    lena++;
                }
            }
        }
    }
    for (int i = lena - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
