//
// Created by Geek.Kwok on 2026/4/28.
//
#include <iostream>
using namespace std;

int a[105][105], f[105], c[105], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) f[i] = 1e9;
    f[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] && f[i] > a[i][j] + f[j]) f[i] = a[i][j] + f[j], c[i] = j;
        }
    }
    cout << "minlong=" << f[1] << endl << 1 << " ";
    int k = 1;
    while(c[k]) cout << c[k] << " ", k = c[k];
    return 0;
}