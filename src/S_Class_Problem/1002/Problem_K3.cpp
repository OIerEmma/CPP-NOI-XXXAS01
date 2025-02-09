//
// Created by Emma on 2025/2/7.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r = i;
        while (r > 0) {
            if (r % 10 == 1) {
                ans++;
            }
            r /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}
