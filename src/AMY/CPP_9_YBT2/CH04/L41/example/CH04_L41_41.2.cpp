//
// Created by Amy on 2026/7/21.
//
#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    if (abs(a) > abs(b) || abs(a) == abs(b) && a > b) swap(a, b);
    if (abs(b) > abs(c) || abs(b) == abs(c) && b > c) swap(b, c);
    if (abs(a) > abs(b) || abs(a) == abs(b) && a > b) swap(a, b);
    cout << a << ' ' << b << ' ' << c;
    return 0;
}
