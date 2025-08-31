//
// Created by Emma on 2025/8/15.
//
#include<iostream>
using namespace std;

int a[1001];

int main() {
    int n, lena = 1;
    cin >> n;
    a[1] = 2;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= lena; j++) {
            a[j] *= 2;
        }
        for (int j = 1; j <= lena; j++) {
            if (a[j] > 9) {
                a[j + 1]++;
                a[j] -= 10;
                if (j == lena) {
                    lena++;
                }
            }
        }
        a[1] += 2;
        int cnt = 1;
        while (a[cnt] > 9) {
            a[cnt] %= 10;
            a[cnt + 1]++;
            cnt++;
            if (cnt >= lena) {
                lena++;
            }
        }
    }
    for (int i = lena; i >= 1; i--) {
        cout << a[i];
    }
    return 0;
}
