//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 21;
long long a[maxn][maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[1][i] = 1;
        a[i][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            a[i][j] = a[i][j - 1] + a[i - 1][j];
        }
    }
    cout << a[n][n] << endl;
    return 0;
}