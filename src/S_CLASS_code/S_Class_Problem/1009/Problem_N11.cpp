//
// Created by Emma on 2025/7/27.
//
#include<iostream>
using namespace std;

int a[210];

int main() {
    int n, k, i;
    while (cin >> n) {
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        for (i = 0; i < n; i++) {
            if (a[i] == k) {
                cout << i << endl;
                break;
            }
        }
        if (i == n) {
            cout << -1 << endl;
        }
    }
    return 0;
}
