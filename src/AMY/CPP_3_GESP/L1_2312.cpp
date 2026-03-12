//
// Created by Amy on 2026/2/8.
//
#include<iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    if ((x + n) % 7 == 0) {
        cout << 7 << endl;
    } else {
        cout << (x + n) % 7;
    }
    return 0;
}
