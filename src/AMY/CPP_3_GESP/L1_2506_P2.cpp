//
// Created by Amy on 2026/3/7.
//
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int m, n;
    cin >> m >> n;
    int lcm = m / gcd(m, n) * n;
    cout << lcm << endl;
    return 0;
}