//
// Created by Emme.Kwok on 2026/2/3.
//
#include<iostream>
using namespace std;

int m[12][22], p[12][22];

int main() {
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = j + 1; l <= n; l++) {
                p[j][l] = p[l][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            ans += p[i][j];
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans / 2 << endl;
    return 0;
}