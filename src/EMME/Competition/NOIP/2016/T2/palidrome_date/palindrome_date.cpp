//
// Created by Geek.Kwok on 2026/10/4.
//
#include<bits/stdc++.h>
using namespace std;

int change(int n) {
    int y = n / 10000, m = n % 10000 / 100, d = n % 100;
    if (m == 2) {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
            if (d > 29) d -= 29, m++;
        } else {
            if (d > 28) d -= 28, m++;
        }
        // cout << "in";
    } else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d > 31) d -= 31, m++;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) d -= 30, m++;
    }
    if (m >= 13) y++, m -= 12;
    // cout << y << " " << m << " " << d << endl;
    return y * 10000 + m * 100 + d;
}

bool isp(string s) {
    for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int d1, d2, ans = 0;
    cin >> d1 >> d2;
    for (int i = d1; i <= d2; i++) {
        i = change(i);
        if (isp(to_string(i))) ans++;
    }
    cout << ans << endl;
    return 0;
}