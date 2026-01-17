//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    int m, k, num3 = 0;
    cin >> m >> k;
    int m2 = m;
    while (m2 > 0) {
        if (m2 % 10 == 3) {
            num3 ++;
        }
        m2 /= 10;
    }
    if (num3 == k && m % 19 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}