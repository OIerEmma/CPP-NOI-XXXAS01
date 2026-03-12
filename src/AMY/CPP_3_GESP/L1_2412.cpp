//
// Created by Amy on 2026/3/1.
//
#include <iostream>
using namespace std;

int main() {
    double K, F, C;
    cin >> K;
    C = K - 273.15;
    F = C*1.8 + 32;
    if (F>212) {
        cout<<"Temperature is too high!";
    }else {
        printf("%.2f %.2f",C, F);
    }
    return 0;
}