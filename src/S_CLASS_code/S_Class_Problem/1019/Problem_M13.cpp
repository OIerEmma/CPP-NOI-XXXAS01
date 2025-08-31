//
// Created by Emma on 2025/8/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i + j == n && i * 2 + j * 4 == m) {
                cout << "ji:" << i << " tu:" << j << endl;
                break;
            }
        }
    }
    return 0;
}