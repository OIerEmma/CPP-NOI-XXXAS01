//
// Created by Emma on 2024/11/24.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    unsigned long long n, x, y;
    double eat, remain;
    cin >> n >> x >> y;
    if(n == 0 || x == 0) {
        cout << 0 << endl;
    } else if(y == 0) {
        cout << n << endl;
    } else {
        eat = y * 1.0 / x;
        remain = n - eat;
        if(remain < 0) {
            cout << 0 << endl;
        } else {
            cout << int(remain) << endl;
        }
    }
    return 0;
}