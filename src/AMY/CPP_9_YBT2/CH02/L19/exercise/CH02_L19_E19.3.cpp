//
// Created by Amy on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;
int a, b, c, rs, ss;
int main() {
    cin >> a >> b >> c;
    rs = b * c;
    ss = a * a;
    if (rs > ss) {
        cout << "RECTANGLE";
    }
    if (ss > rs) {
        cout << "SQUARE";
    }
    if (ss == rs) {
        cout << "SAME";
    }
    return 0;
}
