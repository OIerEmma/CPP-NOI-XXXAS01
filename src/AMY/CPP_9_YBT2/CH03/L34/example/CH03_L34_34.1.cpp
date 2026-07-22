//
// Created by Amy on 2026/7/13.
//
#include<bits/stdc++.h>
using namespace std;
int x;
int main() {
    while (cin >> x) {
        if (x >= 40) cout << 100;
        else if (x >= 0 && x <= 10) cout << 6 * x;
        else if (x >= 11 && x <= 20) cout << 60 + 2 * (x - 10);
        else if (x >= 21 && x <= 40) cout << 80 + 1 * (x - 20);
        cout << endl;
    }
    return 0;
}