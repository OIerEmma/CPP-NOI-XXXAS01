//
// Created by Amy on 2026/2/4.
//
#include<iostream>
using namespace std;

int main() {
    int x, y, z, q;
    cin >> x >> y >> z >> q;
    if (x * 2 + y * 5 + z * 3 <= q) {
        cout << "Yes" << endl << q - (x * 2 + y * 5 + z * 3);
    } else {
        cout << "No" << endl << (x * 2 + y * 5 + z * 3) - q;
    }
    return 0;
}
