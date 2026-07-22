//
// Created by Amy on 2026/7/15.
//
#include <iostream>
using namespace std;

int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int sum = a[2][0] + a[1][1] + a[0][2];
    cout << sum << endl;
    return 0;
}
