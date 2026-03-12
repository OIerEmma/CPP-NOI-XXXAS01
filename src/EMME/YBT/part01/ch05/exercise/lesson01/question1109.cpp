//
// Created by Emma on 2025/1/19.
//
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        b[i] = 1;
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i] % j == 0)
                b[i] = -b[i];
        }
    }
    cout << 1;
    for (int i = 2; i <= n; i++) {
        if (b[i] == -1)
            cout << "," << a[i];
    }

    return 0;
}
