//
// Created by Emme.Kwok on 2026/3/28.
//
#include<iostream>
using namespace std;

int main() {
    int n, k, ans = 101;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (k % x == 0) {
            ans = min(ans, k / x);
        }
    }
    cout << ans << endl;
    return 0;
}