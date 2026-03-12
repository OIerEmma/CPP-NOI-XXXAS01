//
// Created by Emma on 2024/12/22.
//
#include<iostream>
using namespace std;

int main() {
    int x, x2, y, y2, n;
    cin >> n >> x >> x2;
    double const baseline = x2 * 1.0 / x * 100;
    for (int i = 1; i < n; i++) {
        cin >> y >> y2;
        if (y2 * 1.0 / y * 100 - baseline > 5) {
            cout << "better" << endl;
        } else if (baseline - y2 * 1.0 / y * 100 > 5) {
            cout << "worse" << endl;
        } else {
            cout << "same" << endl;
        }
    }
    return 0;
}
