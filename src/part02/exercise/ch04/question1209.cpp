//
// Created by Emma on 2025/4/4.
//
#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main() {
    int n, num, d, tmp1, tmp2;
    char c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp1 >> c >> tmp2;
        if (i == 1) {
            num = tmp1;
            d = tmp2;
        } else {
            num = num * tmp2+ tmp1 * d;
            d *= tmp2;
        }
    }
    int tmp = gcd(num, d);
    num /= tmp;
    d /= tmp;
    if (d == 1) {
        cout << num;
    } else {
        cout << num << "/" << d << endl;
    }
    return 0;
}