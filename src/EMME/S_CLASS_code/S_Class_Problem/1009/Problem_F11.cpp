//
// Created by Emma on 2025/7/13.
//
#include<iostream>
#include<cstring>
using namespace std;

int a[10010];

int main() {
    int l, m, x, y;
    for (; ;) {
        cin >> l >> m;
        if (l == 0 && m == 0) {
            break;
        }
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            for (int k = x; k <= y; k++) {
                a[k] = -1;
            }
        }
        int ans = 0;
        for (int j = 0; j <= l; j++) {
            if (a[j] != -1) {
                ans++;
            }
        }
        cout << ans << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}
