//
// Created by Geek.Kwok on 2026/4/27.
//
#include <iostream>
using namespace std;

int n, a[205][5], L, K;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][1], a[i][2] = 1, a[i][3] = 0;
    for (int i = n - 1; i >= 1; i--) {
        L = 0, K = 0;
        for (int j = i + 1; j <= n; j++) {
            if (a[j][1] >= a[i][1] && a[j][2] > L) L = a[j][2], K = j;
        }
        if (L > 0) a[i][2] = L + 1, a[i][3] = K;
    }

    K = 1;
    for (int i = 1; i <= n; i++) if (a[i][2] > a[K][2]) K = i;
    cout << "max=" << a[K][2] << endl;
    while (K != 0) {
        cout << a[K][1] << " ";
        K = a[K][3];
    }
}