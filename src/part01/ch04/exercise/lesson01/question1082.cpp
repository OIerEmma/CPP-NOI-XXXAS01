//
// Created by Emma on 2024/12/28.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        a %= b;
        a *= 10;
    }
    cout << a / b << endl;
    return 0;
}