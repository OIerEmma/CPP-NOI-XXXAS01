//
// Created by Amy on 2026/6/25.
//
#include<bits/stdc++.h>
using namespace std;
int h;
int main() {
    cin >> h;
    if (h < 10) cout << 1;
        else if (h < 100) cout << 2;
        else if (h < 1000) cout << 3;
        else if (h < 10000) cout << 4;
        else if (h < 100000) cout << 5;
    return 0;
}
