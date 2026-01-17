//
// Created by Emma on 2025/8/14.
//
#include<iostream>
using namespace std;

int a[100001];

int main() {
    int n, lena = 1;
    cin >> n;
    a[0] = 1;
    for (int i = 2; i <= n; i++) {
        a[0] += i;
        for (int j = 0; j < lena; j++) {
            if (a[j] < 10) {
                break;
            }
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
    return 0;
}