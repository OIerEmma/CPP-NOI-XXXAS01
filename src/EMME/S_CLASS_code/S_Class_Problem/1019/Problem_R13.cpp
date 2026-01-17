//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            for (int k = 1; k < m - 1; k++) {
                if (i + j + k == m && i * 15 + j * 10 + k * 5 == n) {
                    cout << "mu:" << i << " gong:" << j << " xiao:" << k << endl;
                }
            }
        }
    }
    return 0;
}