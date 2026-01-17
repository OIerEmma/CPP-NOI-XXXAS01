//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

int a[1010], b[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * b[i];
    }
    cout << ans << endl;
    return 0;
}