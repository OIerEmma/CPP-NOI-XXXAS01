//
// Created by Emme.Kwok on 2026/3/28.
//
#include<iostream>
using namespace std;

int main() {
    int k, r;
    cin >> k >> r;
    for (int i = 1; ; i++) {
        if ((i * k - r) % 10 == 0 || i * k % 10 == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}