//
// Created by Amy on 2026/7/11.
//
#include<bits/stdc++.h>
using namespace std;
int n, j, x;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == 0) {
            cout << 0 << endl;
            continue;
        }
        j = 1;
        while(x) {
            j *= x % 10;
            x /= 10;
            if (j == 0) break;
        }
        cout << j << endl;
    }
    return 0;
}
