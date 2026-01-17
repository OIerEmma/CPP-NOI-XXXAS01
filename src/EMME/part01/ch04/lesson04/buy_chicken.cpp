//
// Created by Emma on 2025/1/3.
//
#include<iostream>
using namespace std;

int main() {
    for (int a = 0; a < 100; a ++) {
        for (int b = 0; b < 100; b ++) {
            for (int c = 0; c < 100; c ++) {
                if (5 * a + 3 * b + c / 3 == 100 &&  a + b + c == 100&& c % 3 == 0) {
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
    return 0;
}
