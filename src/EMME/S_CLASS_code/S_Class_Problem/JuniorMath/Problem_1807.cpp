//
// Created by Emme.Kwok on 2025/9/20.
//
#include<iostream>
using namespace std;

int main() {
    int a, r = 0;
    while (cin >> a) {
        if (a <= 100000) {
            r = int(a * 0.1);
        } else if (a <= 200000) {
            r += int(100000 * 0.1);
            r += int((a - 100000) * 0.075);
        } else if (a <= 400000) {
            r += int(100000 * 0.1);
            r += int(100000 * 0.075);
            r += int((a - 200000) * 0.05);
        } else if (a <= 600000) {
            r += int(100000 * 0.1);
            r += int(100000 * 0.075);
            r += int(200000 * 0.05);
            r += int((a - 400000) * 0.03);
        } else if (a <= 1000000) {
            r += int(100000 * 0.1);
            r += int(100000 * 0.075);
            r += int(200000 * 0.05);
            r += int(200000 * 0.03);
            r += int((a - 600000) * 0.015);
        } else {
            r += int(100000 * 0.1);
            r += int(100000 * 0.075);
            r += int(200000 * 0.05);
            r += int(200000 * 0.03);
            r += int(400000 * 0.015);
            r += int((a - 1000000) * 0.01);
        }
        cout << r << endl;
        r = 0;
    }
    return 0;
}
