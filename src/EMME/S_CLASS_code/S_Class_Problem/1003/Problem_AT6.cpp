//
// Created by Emma on 2025/7/5.
//
#include <iostream>
using namespace std;

int a[110][110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[j][i] << ' ';
        }
        cout << endl;
    }
    return 0;
}