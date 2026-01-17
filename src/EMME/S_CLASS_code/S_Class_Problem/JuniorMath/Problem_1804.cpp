//
// Created by Emme.Kwok on 2025/9/20.
//
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    int x, y;
    while(cin >> x) {
        cin >> y;
        cout << gcd(x, y) << " " << lcm(x, y) << endl;
    }
    return 0;
}