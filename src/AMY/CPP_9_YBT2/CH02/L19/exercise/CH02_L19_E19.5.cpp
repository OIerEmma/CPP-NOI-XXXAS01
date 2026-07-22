//
// Created by Amy on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;
int m, d;
int main() {
    cin >> m >> d;
    if (m >= 1 && m <= 12) {
        if (m == 1 && (d == 25 || d == 26 || d == 27 || d == 28 || d == 29 || d == 30 || d == 31)) {
            cout << "Mouse";
        }
        else if (m != 1) {
            cout << "Mouse";
        }
        else if (m == 1) {
            cout << "Pig";
        }
    }
    return 0;
}
