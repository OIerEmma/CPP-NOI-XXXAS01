//
// Created by Emma on 2024/11/19.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    long long a, b, c, d, e;
    scanf("%ld %ld %ld %ld %ld", &a, &b, &c, &d, &e);
    a = a / 3; b = b + a; e = e + a;
    b = b / 3; c = c + b; a = a + b;
    c = c / 3; d = d + c; b = b + c;
    d = d / 3; e = e + d; c = c + d;
    e = e / 3; a = a + e; d = d + e;
    printf("%5ld%5ld%5ld%5ld%5ld\n", a, b, c, d, e);
    return 0;
}