//
// Created by Emma on 2025/2/22.
//
#include <iostream>
using namespace std;

int sum(int a) {
    int m = 0;
    for (int i = a - 1; i > 0; i--) {
        if (a % i == 0) {
            m += i;
        }
    }
    return m;
}

int main() {
    for (int a = 4; a < 500; a++) {
        int b = sum(a);
        int c = sum(b);
        if (b != 1 && c != 1 && a != b) {
            if (c == a) {
                cout << a << ' ' << b << endl;
                break;
            }
        }
    }
    return 0;
}
