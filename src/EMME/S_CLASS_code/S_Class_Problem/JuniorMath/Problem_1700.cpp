//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int s = 1; s <= t; s++) {
        cin >> n;
        int ans = 0, add = 1;
        for (int i = 1; i <= n; i++) {
            ans += add;
            add += 2;
            ans %= 10000;
        }
        cout << ans << endl;
    }
    return 0;
}