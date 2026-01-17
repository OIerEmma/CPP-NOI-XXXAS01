//
// Created by Emma on 2025/7/29.
//
#include<iostream>
using namespace std;

int main() {
    long long a;
    while (cin >> a) {
        if (a < 8) {
            cout << a << endl;
        } else {
            string s;
            while (a >= 8) {
                s = to_string(a % 8) + s;
                a /= 8;
            }
            s = to_string(a % 10) + s;
            cout << s << endl;
        }
    }
    return 0;
}