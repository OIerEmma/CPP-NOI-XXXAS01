//
// Created by Amy on 2026/2/8.
//
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m % 1 == 0) {
        for (int i = 1; i <= n; i++) {
            if (i % m != 0) {
                cout << i << endl;
            }
        }
    }
    return 0;
}
