//
// Created by Emma on 2024/11/23.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int m;
    cin >> m;
    int a = m / 100;
    int b = (m / 10) % 10;
    int c = m % 10;
    int n = c * 100 + b * 10 + a;
    if(n < 100 && n >= 10) {
        cout << "0" << n;
    }
    else if(n < 10) {
        cout << "00" << n;
    }
    else {
        cout << n << endl;
    }
    return 0;
}
