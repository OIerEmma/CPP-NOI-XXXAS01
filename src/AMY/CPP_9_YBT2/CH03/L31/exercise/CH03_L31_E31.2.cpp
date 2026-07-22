//
// Created by Amy on 2026/7/10.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int neg = 0, zero = 0, pos = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) ++neg;
        else if (x == 0) ++zero;
        else ++pos;
    }

    cout << neg << " " << zero << " " << pos << endl;
    return 0;
}