//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int x[5];

int main() {
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    int a, b, c;
    for (int i = 0; i < 4; i++) {
        a = x[i], b = x[(i + 1) % 4], c = x[(i + 2) % 4];
        if (a + b > c && a + c > b && c + b > a) {
            cout << "TRIANGLE";
            return 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        a = x[i], b = x[(i + 1) % 4], c = x[(i + 2) % 4];
        if (a == 0 || b == 0 || c == 0 || a + b == c || a + c == b || b + c == a) {
            cout << "SEGMENT";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}