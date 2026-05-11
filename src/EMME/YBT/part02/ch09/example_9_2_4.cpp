//
// Created by Emme.Kwok on 2026/4/26.
//
#include<iostream>
using namespace std;

int a[1005][1005][5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j][1];
            a[i][j][2] = a[i][j][1];
            a[i][j][3] = 0;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (a[i + 1][j][2] > a[i + 1][j + 1][2]) {
                a[i][j][2] += a[i + 1][j][2];
                a[i][j][3] = 0;
            } else {
                a[i][j][2] += a[i + 1][j + 1][2];
                a[i][j][3] = 1;
            }
        }
    }
    cout << a[1][1][2] << endl;
    // int j = 1;
    //    // for (int i = 1; i < n; i++) {
    //    //     cout << a[i][j][1] << "->";
    //    //     j = j + a[i][j][3];
    //    // }
    //    // cout << a[n][j][1] << endl;
    return 0;
}