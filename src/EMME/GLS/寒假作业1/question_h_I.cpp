//
// Created by Emme.Kwok on 2026/1/23.
//
#include<iomanip>
#include<iostream>
using namespace std;

int main() {
    double a, b, c, d, x;
    cin >> x >> a >> b >> c >> d;
    cout << fixed << setprecision(7) << a * x * x * x + b * x * x + c * x + d << endl;
    return 0;
}