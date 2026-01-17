//
// Created by Emma on 2025/8/4.
//
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}