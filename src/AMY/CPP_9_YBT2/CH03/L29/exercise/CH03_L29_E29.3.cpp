//
// Created by Amy on 2026/7/8.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int R, M, Y;
    cin >> R >> M >> Y;
    double result = M * pow(1.0 + R / 100.0, Y);
    cout << (long long)(result + 1e-9) << endl;
    return 0;
}