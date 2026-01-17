//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0) {
            cout << n << "/2=" << n / 2 << endl;
            n /= 2;
        } else {
            cout << n << "*3+1=" << n * 3 + 1 << endl;
            n *= 3;
            n++;
        }
    }
    return 0;
}