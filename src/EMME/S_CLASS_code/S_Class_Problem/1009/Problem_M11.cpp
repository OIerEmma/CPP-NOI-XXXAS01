//
// Created by Emma on 2025/7/27.
//
#include<iostream>
using namespace std;

int main() {
    int n, m;
    while (cin >> n) {
        m = n + 2 * (n - 1);
        int t = n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m - t; j++) {
                cout << " ";
            }
            for (int j = 1; j <= t; j++) {
                cout << "*";
            }
            t += 2;
            cout << endl;
        }
    }
    return 0;
}