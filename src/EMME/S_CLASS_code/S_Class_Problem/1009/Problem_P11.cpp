//
// Created by Emma on 2025/7/27.
//
#include<iostream>
using namespace std;

int a[110], x[110];

int main() {
    int n, m;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> x[i];
        }
        for (int i = 1, j; i <= m; i++) {
            bool flag = true;
            for (j = 1; j <= n; j++) {
                if (a[j] == x[i]) {
                    cout << "YES" << endl;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}