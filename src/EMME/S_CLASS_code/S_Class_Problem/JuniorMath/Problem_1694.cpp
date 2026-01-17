//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> c;
        if (a * a + b * b == c * c || a * a + c * c == b * b
            || a * a == b * b + c * c) {
            cout << "good" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "perfect" << endl;
        } else {
            cout << "just a triangle" << endl;
        }
    }
    return 0;
}
