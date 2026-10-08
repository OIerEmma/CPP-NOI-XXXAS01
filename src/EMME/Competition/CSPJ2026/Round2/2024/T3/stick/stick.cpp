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
                int remain = len - pos; // 剩余的位数
                for (int dg = (pos == 1 ? 1 : 0); dg <= 9; dg++) { // 贪心：从小到大的尝试数字并确保剩余小木棍可以拼出剩余数字
                    int r = rest - c[dg]; // 剩余的小木棍数量
                    if (r >= 2 * remain && r <= 7 * remain) { // 剩余小木棍r可以拼出剩余数字
                        ans += (char)('0' + dg);
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