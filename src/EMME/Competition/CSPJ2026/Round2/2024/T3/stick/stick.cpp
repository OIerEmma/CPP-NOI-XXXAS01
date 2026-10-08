//
// Created by Geek.Kwok on 2026/10/6.
//
#include<bits/stdc++.h>
using namespace std;

const int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) cout << "-1\n";
        else {
            int len = ceil(n * 1.0 / 7);
            string ans;
            int rest = n;
            for (int pos = 1; pos <= len; pos++) {
                int remain = len - pos;
                for (int dg = (pos == 1 ? 1 : 0); dg <= 9; dg++) {
                    int r = rest - c[dg];
                    if (r >= 2 * remain && r <= 7 * remain) {
                        ans += char('0' + dg);
                        rest = r;
                        break;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}