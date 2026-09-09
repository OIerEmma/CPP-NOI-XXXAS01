//
// Created by Geek.Kwok on 2026/9/9.
//
#include <bits/stdc++.h>
using namespace std;

int fingerprint(int x) {
    int res = 0;
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) {
            x /= i;
            res ^= 1 << (i - 1); // 把x的质因子i的奇偶打进整数的第i-1位
        }
    if (x > 1) res ^= 1 << (x - 1);
    return res;
}

int main() {
    int n; cin >> n;
    unordered_map<int, long long> cnt;
    cnt[0] = 1;
    int pre = 0; long long ans = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        pre ^= fingerprint(a); // 录指纹
        ans += cnt[pre]; // pre[l-1] = pre[r]
        cnt[pre]++;
    }
    cout << ans << endl;
    return 0;
}