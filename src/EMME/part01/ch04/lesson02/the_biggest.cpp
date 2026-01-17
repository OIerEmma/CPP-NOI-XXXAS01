//
// Created by Emma on 2025/1/1.
//
#include<iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int r = m % n;
    while (r != 0) {
        m = n;
        n = r;
        r = m % n;
    }
    cout << n << endl;
    return 0;
}