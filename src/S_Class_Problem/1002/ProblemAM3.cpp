//
// Created by Emma on 2025/2/20.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, x, y, sum = 0;
    cin >> a >> b >> c;
    for (x = 0; x <= c; x++) {
        for (y = 0; y <= c; y++) {
            if (a * x + b * y == c) {
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}