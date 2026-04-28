//
// Created by Geek.Kwok on 2026/4/28.
//
#include <iostream>
using namespace std;

bool a[205][205];
int w[205], f[205], c[205], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    int x, y;
    do {
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        a[x][y] = true;
    } while (true);

    f[n] = w[n];
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] && f[i] < w[i] + f[j]) {
                f[i] = w[i] + f[j];
                c[i] = j;
            }
        }
    }

    int k = 1;
    for (int i = 2; i <= n; i++) if (f[k] < f[i]) k = i;
    int maxx = f[k];
    cout << k;
    while (c[k]) {
        cout << "-" << c[k];
        k = c[k];
    }
    cout << endl << maxx << endl;
    return 0;
}