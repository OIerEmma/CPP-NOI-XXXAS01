//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    if (m == 0 || m == 1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}