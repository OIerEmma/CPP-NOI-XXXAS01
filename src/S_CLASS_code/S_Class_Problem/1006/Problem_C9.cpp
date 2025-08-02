//
// Created by Emma on 2025/7/9.
//
#include<iostream>
using namespace std;

int f[1010];

int main() {
    int n, p;
    cin >> n >> p;
    f[p] = 2 * p;
    for (int i = p + 1; i <= n; i++) {
        f[i] = f[i - 1] + i;
    }
    if (p <= 2) {
        cout << 2 << endl;
    } else {
        cout << f[n] << endl;
    }
    return 0;
}
