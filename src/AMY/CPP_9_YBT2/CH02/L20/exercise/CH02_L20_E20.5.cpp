//
// Created by Amy on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;
int x, y;
int main() {
    cin >> x >> y;
    if ((x == 1 && y == -1) || (x == -1 && y == 1) || (x == 1 && y == 1) || (x == -1 && y == -1) || (x == 0 && y == 0)) {
        cout << "yes";
    }else {
        cout << "no";
    }
    return 0;
}
