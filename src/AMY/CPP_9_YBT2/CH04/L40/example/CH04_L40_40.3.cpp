//
// Created by Amy on 2026/7/19.
//
#include<bits/stdc++.h>
using namespace std;

char a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, x;
int sum, ys;

int main() {
    cin >> a1 >> x >> a2 >> a3 >> a4 >> x >> a5 >> a6 >> a7 >> a8 >> a9 >> x >> a10;
    sum = (a1 - '0') * 1 + (a2 - '0') * 2 + (a3 - '0') * 3 + (a4 - '0') * 4 + (a5 - '0') * 5 + (a6 - '0') * 6 + (
              a7 - '0') * 7 + (a8 - '0') * 8 + (a9 - '0') * 9;
    ys = sum % 11;
    if (ys == a10 - '0' || ys == 10 && a10 == 'X') cout << "Right";
    else {
        cout << a1 << '-' << a2 << a3 << a4 << '-' << a5 << a6 << a7 << a8 << a9 << '-';
        if (ys < 10) cout << ys;
        else cout << "X";
    }
    return 0;
}
