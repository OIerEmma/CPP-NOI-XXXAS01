//
// Created by Emma on 2025/8/13.
//
#include <iostream>
using namespace std;

int a[5001], c[10001];

int main() {
    int n, lena = 1, lenc = 1;
    cin >> n;
    // 初始化
    a[0] = 1;
    c[0] = 1;
    for (int i = 2; i <= n; i++) {
        // 计算i的阶乘
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
        // 把算出的a加到c上
        if (lena > lenc) {
            lenc = lena;
        }
        for (int j = 0; j < lenc; j++) {
            c[j] += a[j];
            c[j + 1] += c[j] / 10;
            if (j == lenc - 1 && c[j] >= 10) {
                lenc++;
            }
            c[j] %= 10;
        }
    }
    for (int i = lenc - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
