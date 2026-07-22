//
// Created by Amy on 2026/7/15.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y, a, cnt = 0;
    cin >> x >> y;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; i <= y; j++) {
            cin >> a;
            if (i == 1 || i == x || j == 1 || j == y) cnt += a;
        }
    }
    cout << cnt;
    return 0;
}