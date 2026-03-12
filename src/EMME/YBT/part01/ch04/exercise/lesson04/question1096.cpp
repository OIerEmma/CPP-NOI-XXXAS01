//
// Created by Emma on 2025/1/5.
//
#include<iostream>
using namespace std;

int main() {
    int ans = 0, L, R, i, n;
    cin >> L >> R;
    for (i = L; i <= R; i++) {
        n = i;
        while (n) {
            if (n % 10 == 2) {
                ans++;
            }
            n /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}