//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == a && i % 5 == b && i % 7 == c) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}