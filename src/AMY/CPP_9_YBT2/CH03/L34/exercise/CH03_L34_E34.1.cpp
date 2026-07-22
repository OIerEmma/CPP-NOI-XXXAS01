//
// Created by Amy on 2026/7/13.
//
#include <iostream>
using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) {
            break;
        }
        int carryCount = 0;
        int carry = 0;
        for (int i = 0; i < 3; i++) {
            int digitM = m % 10;
            int digitN = n % 10;
            int sum = digitM + digitN + carry;
            if (sum >= 10) {
                carryCount++;
                carry = 1;
            } else {
                carry = 0;
            }
            m /= 10;
            n /= 10;
        }
        cout << carryCount << endl;
    }
    return 0;
}
