//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;
int a[1000010][5];

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    cin >> x >> y;
    for (int t = n - 1; t >= 0; t--) {
        if (a[t][0] <= x && a[t][2] + a[t][0] >= x && a[t][1] <= y && a[t][3] + a[t][1] >= y) {
            cout << t + 1 << endl;
            break;
        }
        if (t == 1) {
            cout << -1 << endl;
            break;
        }
    }
    cout << "此题超纲，先放一放吧~" << endl;
    return 0;
}
