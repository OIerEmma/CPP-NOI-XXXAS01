//
// Created by Emme.Kwok on 2026/8/29.
//
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { // 最大公约数
    while (b) { // 辗转相除法
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) { // 最小公倍数
    return a * b / gcd(a, b); // 运用公式：(a, b) * [a, b] = a * b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << lcm(a, b);
    return 0;
}