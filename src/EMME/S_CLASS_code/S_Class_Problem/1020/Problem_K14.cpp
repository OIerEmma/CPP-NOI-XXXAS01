//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[81];

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}