//
// Created by Amy on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;
int x, y;
int main() {
    cin >> x >> y;
    if (x < 60 && y >= 60 || x >= 60 && y < 60)
        cout << 1;
    else cout << 0;
    return 0;
}
