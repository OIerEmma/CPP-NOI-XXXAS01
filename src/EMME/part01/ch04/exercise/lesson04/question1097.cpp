//
// Created by Emma on 2025/1/11.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, d, j, i;
    char c;
    cin >> a >> b >> c >> d;
    if (d == 1) {
        for (j = 1; j <= a; j++) {
            for (i = 1; i <= b; i++) {
                cout << c;
            }
            cout << endl;
        }
    } else {
        for (j = 1; j <= a; j++) {
            for (i = 1; i <= b; i ++) {
                if (j == 1 || j == a || i == 1 || i == b) {
                    cout << c;
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}