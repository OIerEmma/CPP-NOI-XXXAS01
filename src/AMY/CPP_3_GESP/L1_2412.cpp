//
// Created by Amy on 2026/3/1.
//
#include <iostream>
using namespace std;

int main() {
    double k, f, c;
    cin >> k;
    c = k - 273.15;
    f = c*1.8 + 32;
    if (f>212) {
        cout<<"Temperature is too high!";
    }else {
        printf("%.2f %.2f",c, f);
    }
    return 0;
}