//
// Created by Emme.Kwok on 2025/9/19.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, t;
    cin >> t;
    for (int s = 1; s <= t; s++) {
        cin >> a >> b >> c;
        bool flag = false;
        for (int i = 1000; i <= 9999; i++) {
            if (i % a == 0 && (i + 1) % b == 0 && (i + 2) % c == 0) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}