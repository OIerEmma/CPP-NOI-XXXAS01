//
// Created by Emma on 2025/7/27.
//
#include<iostream>
using namespace std;

int a[1010];

int main() {
    int n, k;
    for ( ; ; ) {
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cin >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
