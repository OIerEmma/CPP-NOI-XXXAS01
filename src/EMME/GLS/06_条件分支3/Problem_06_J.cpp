//
// Created by Emme.Kwok on 2026/3/14.
//
#include<iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    if (n > m / 2) {
        cout << m / 2 << endl;
    } else if (n == m / 2) {
        cout << n << endl;
    } else {
        long long s = (m / 2 - n) * 2;
        s /= 4;
        cout << s + n << endl;
    }
    return 0;
}