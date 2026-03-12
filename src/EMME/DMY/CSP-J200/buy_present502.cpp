//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

int a[1005];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] > a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i];
        if (ans >= k) {
            cout << i << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
    return 0;
}