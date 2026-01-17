//
// Created by Emma on 2025/8/11.
//
#include <iostream>
using namespace std;

int a[5005][5005], f[5005][5005];

int main() {
    int group;
    cin >> group;
    for (int i = 0; i < group; i++) {
        int m, n;
        char ch;
        cin >> m >> n;
        memset(f, 0, sizeof(f));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> ch;
                if (ch == '+') {
                    a[j][k] = 1;
                } else if (ch == '-') {
                    a[j][k] = -1;
                }
            }
        }
        f[m - 1][n - 1] = 0;
        for (int j = m - 1; j > 0; j--) {
            for (int k = n - 1; k > 0; k--) {
                if (j == m - 1) {
                    f[j][k - 1] = f[j][k] + a[j][k];
                } else if (k == n - 1) {
                    f[j - 1][k] = f[j][k] + a[j][k];
                } else if (j < m - 1 && k < n - 1) {
                    if (a[j][k - 1] + f[j][k - 1] < a[j - 1][k] + f[j - 1][k]) {
                        f[j - 1][k - 1] = a[j - 1][k] + f[j - 1][k];
                    } else {
                        f[j - 1][k - 1] = a[j][k - 1] + f[j][k - 1];
                    }
                }
            }
        }
        // for (int j = 0; j < m; j ++) {
        //     for (int k = 0; k < n; k ++) {
        //         cout << f[j][k] << " ";
        //     }
        //     cout << endl;
        // }

        // 输出路径
        int fwin = 0, xwin = 0;
        int j = 0, k = 0;
        int path = m + n - 2;
        while (path > 0) {
            int t = 0;
            if (f[j + 1][k] < f[j][k + 1]) {
                t = a[j][k + 1];
                k++;
            } else {
                t = a[j + 1][k];
                j++;
            }
            if (path % 2 == 0) {
                fwin += t;
            } else {
                xwin += t;
            }
            path--;
        }
        if (fwin > xwin) {
            cout << "FWin" << endl;
        } else if (fwin < xwin) {
            cout << "XWin" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
    return 0;
}
