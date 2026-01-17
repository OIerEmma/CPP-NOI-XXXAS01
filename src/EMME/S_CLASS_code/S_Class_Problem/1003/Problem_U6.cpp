//
// Created by Emma on 2025/7/2.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    int maxx = -1000001;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != maxx) {
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}