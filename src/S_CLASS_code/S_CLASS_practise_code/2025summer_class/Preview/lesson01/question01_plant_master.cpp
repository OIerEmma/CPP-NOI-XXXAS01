//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

int a[110][110];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int x, y, z, r;
    cin >> x >> y >> z >> r;
    swap(a[x][y], a[z][r]);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
