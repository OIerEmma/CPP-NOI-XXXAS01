//
// Created by Emma on 2025/1/2.
//
#include<iostream>
using namespace std;

int main() {
    int m, n, r;
    cin >> m >> n;
    do {
        r = m % n;
        m = n;
        n = r;
    } while (r != 0);
    cout << "the greatest common divisor is:" << m << endl;
    return 0;
}