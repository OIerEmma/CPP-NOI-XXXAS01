//
// Created by Emme.Kwok on 2026/1/27.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    char d;
    int n;
    cin >> d >> n;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (d == 'U') {
            y += i;
            d = 'R';
        } else if (d == 'D') {
            y -= i;
            d = 'L';
        } else if (d == 'L') {
            x -= i;
            d = 'U';
        } else {
            x += i;
            d = 'D';
        }
    }
    cout << x << " " << y << endl;
    return 0;
}