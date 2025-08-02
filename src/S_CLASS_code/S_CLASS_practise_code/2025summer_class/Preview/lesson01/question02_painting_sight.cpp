//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

int a[110][110];

int main() {
    int n, m, n1, n2, m1, m2;
    cin >> n >> m >> n1 >> n2 >> m1 >> m2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n1; i <= n2; i++) {
        for (int j = m1; j <= m2; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
8 6 2 7 3 5
0 0 0 0 0 0
0 0 1 1 1 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 1 1 0
0 0 0 1 0 0
0 0 1 0 1 0
0 0 0 0 0 0
*/
