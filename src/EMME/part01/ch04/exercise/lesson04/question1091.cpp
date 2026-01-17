//
// Created by Emma on 2025/1/5.
//
#include<iostream>
using namespace std;

int main() {
    int s = 0, n, t = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        t *= i;
        s += t;
    }
    printf ("%d\n", s);
    return 0;
}