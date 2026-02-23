//
// Created by Emme.Kwok on 2026/2/5.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i * 4 + j * 7 == n) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}