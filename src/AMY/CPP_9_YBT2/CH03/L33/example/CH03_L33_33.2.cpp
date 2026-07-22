//
// Created by Amy on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;
int a, b, gw, sw;
int main() {
    cin >> a >> b;
    for (int i = 10; i <= 99; i++) {
        gw = i % 10;
        sw = i / 10;
        if (gw + sw == a && abs(gw - sw) == b) {
            cout << i;
            break;
        }
    }

    return 0;
}