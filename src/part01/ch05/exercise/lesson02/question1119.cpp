//
// Created by Emma on 2025/1/22.
//
#include <iostream>
using namespace std;
int m, n, x[5], coordinate[5][5];

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> coordinate[i][j];
        }
    }
    cin >> m >> n;
    for (int i = 0; i < 5; i++) {
        x[i] = coordinate[m - 1][i];
        coordinate[m - 1][i] = coordinate[n - 1][i];
        coordinate[n - 1][i] = x[i];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << coordinate[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
