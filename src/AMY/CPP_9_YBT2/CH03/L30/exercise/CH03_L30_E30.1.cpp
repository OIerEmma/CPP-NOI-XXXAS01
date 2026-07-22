//
// Created by Amy on 2026/7/9.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int baseTotal, baseEffective;
    cin >> baseTotal >> baseEffective;

    for (int i = 0; i < n - 1; ++i) {
        int total, effective;
        cin >> total >> effective;
        long long diff = 1LL * effective * baseTotal - 1LL * baseEffective * total;
        long long left = 20 * diff;
        long long right = 1LL * baseTotal * total;

        if (left > right) {
            cout << "better" << endl;
        } else if (left < -right) {
            cout << "worse" << endl;
        } else {
            cout << "same" << endl;
        }
    }

    return 0;
}
