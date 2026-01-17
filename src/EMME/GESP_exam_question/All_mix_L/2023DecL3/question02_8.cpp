//
// Created by Emma on 2025/3/6.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        char equalchar, questionmarkchar;
        string unit_front, unit_behind;
        cin >> x >> unit_front >> equalchar >> questionmarkchar >> unit_behind;
        if (unit_front == "m") {
            cout << x << " m = " << x * 1000 << " mm";
        } else if (unit_front == "km") {
            if (unit_behind == "mm") {
                cout << x << " km = " << x * 1000000 << " mm";
            } else {
                cout << x << " km = " << x * 1000 << " m";
            }
        } else if (unit_front == "kg") {
            if (unit_behind == "g") {
                cout << x << " kg = " << x * 1000 << " g";
            } else {
                cout << x << " kg = " << x * 1000000 << " mg";
            }
        } else if (unit_front == "g") {
            cout << x << " g = " << x * 1000 << " mg";
        }
    }
    return 0;
}
