//
// Created by Emme.Kwok on 2025/10/13.
//
#include<iostream>
using namespace std;

int s[1010], t[1010], ans;

void compute(int lh, int lm, int h, int m, int ls, int s, int t) {
    if (7 <= lh && lh <= h && h < 23) {
        // 横跨一段：普通时段 + 停车
        ans += (s - ls) * 3 + t * 2;
    } else if (23 <= lh && lh <= h && h < 31) {
        // 横跨一段：夜间时段 + 停车
        ans += (s - ls) * 5 + t * 4;
    } else if (lh < 7 && h >= 7 && h < 23) {
        // 横跨二段：夜间时段 + 普通时段 + 停车
        ans += ((7 - lh) * 60 - lm) * 5;
        ans += ((h - 7) * 60 + m) * 3 + t * 2;
    } else if (lh < 23 && h >= 23 && h < 31) {
        // 横跨二段：普通时段 + 夜间时段 + 停车
        ans += ((23 - lh) * 60 - lm) * 3;
        ans += ((h - 23) * 60 + m) * 5 + t * 4;
    } else if (lh < 7 && h >= 23) {
        // 横跨三段：夜间时段 + 普通满时段 + 夜间时段 + 停车
        ans += ((7 - lh) * 60 - lm) * 5;
        ans += 16 * 60 * 3;
        ans += ((h - 23) * 60 + lm) * 5 + t * 4;
    } else if (lh < 23 && h >= 31) {
        // 横跨三段：普通时段 + 夜间满时段 + 普通时段 + 停车
        ans += ((23 - lh) * 60 - lm) * 3;
        ans += 8 * 60 * 5;
        ans += ((h - 31) * 60 + lm) * 3 + t * 2;
    }
}

int main() {
    int d, n;
    int h, m;
    cin >> d >> h >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
    }
    int lh, lm;
    for (int i = 1; i <= n; i++) {
        // 上次时间
        lh = h;
        lm = m;
        // 本次时间
        m += t[i] + (s[i] - s[i - 1]);
        h += m / 60;
        m %= 60;
        // 计算第i个检查站车费
        compute(lh, lm, h, m, s[i - 1], s[i], t[i]);
        h %= 24;
    }
    if (d > s[n]) {
        // 上次时间
        lh = h;
        lm = m;
        // 本次时间
        m += d - s[n];
        h += m / 60;
        m %= 60;
        compute(lh, lm, h, m, s[n], d, 0);
        h %= 24;
    }
    cout << ans << endl;
    return 0;
}

/*
13 12 0 4
3 3
6 7
10 12
12 5
*/