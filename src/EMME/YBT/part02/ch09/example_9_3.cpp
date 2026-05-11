//
// Created by Emme.Kwok on 2026/4/30.
//
#include<iostream>
using namespace std;

int n, b[205][10], l, k;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i][1], b[i][2] = 1, b[i][3] = 0;
    for (int i = n - 1; i >= 1; i--) {
        l = 0, k = 0;
        for (int j = i + 1; j <= n; j++) {
            if (b[i][1] <= b[j][1] && b[j][2] > l) l = b[j][2], k = j;
        }
        if (l > 0) b[i][2] = l + 1, b[i][3] = k;
    }
    k = 1;
    for (int i = 1; i <= n; i++) if (b[i][2] > b[k][2]) k = i;
    cout << "max=" << b[k][2] << endl;
    while (k) cout << b[k][1] << " ", k = b[k][3];
    return 0;
}