//
// Created by Emma on 2025/1/1.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "End" << endl;
    } else {
        while (n != 1) {
            if (n % 2 == 0) {
                cout << n << "/2=" << n / 2 << endl;
                n /= 2;
            } else {
                cout << n << "*3+1=" << n * 3 + 1 << endl;
                n = n * 3 + 1;
            }
        }
        cout << "End" << endl;
    }
    return 0;
}