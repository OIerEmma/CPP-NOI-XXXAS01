//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    double c, s, a1, a2, a3;
    cin >> c >> s >> a1 >> a2 >> a3;
    double t = c / s + a1 + a2 + a3;
    if (t <= 20) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}