//
// Created by Emma on 2025/6/30.
//
#include<iostream>
using namespace std;

int a[11][11];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool flag1 = true, flag2 = true;
            for (int k = 0; k < n; k++) {
                if (a[i][j] < a[k][j]) {
                    flag1 = false;
                    break;
                }
            }
            if (!flag1) {
                continue;
            }
            for (int k = 0; k < m; k++) {
                if (a[i][j] > a[i][k]) {
                    flag2 = false;
                    break;
                }
            }
            if (flag2) {
                cout << i + 1 << " " << j + 1 << " " << a[i][j] << " ";
                flag = true;
            }
        }
    }
    if (!flag) {
        cout << "not exist" << endl;
    }
    return 0;
}