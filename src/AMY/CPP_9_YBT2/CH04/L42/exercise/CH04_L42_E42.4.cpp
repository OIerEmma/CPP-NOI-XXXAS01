//
// Created by Amy on 2026/7/22.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cnt++;
            }
        }
        if (cnt % 2 == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
