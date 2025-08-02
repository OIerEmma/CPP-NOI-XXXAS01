//
// Created by Emma on 2025/7/11.
//
#include<iostream>
using namespace std;
int a[10001][10001];

int main() {
    int n, x, y;
    int b = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j]; //输入数据
    }
    cin >> x >> y;
    for (int i = n; i >= 1; i--) {
        if ((a[i][1] <= x) && (a[i][3] + a[i][1] >= x) && (a[i][2] <= y) &&
        (a[i][2] + a[i][4] >= y)) {
            cout << i;
            b = 2;
        }
        if (b == 2)
            break;
        if (i == 1) {
            cout << -1;
            break;
        }
    }
    return 0;
}
