//
// Created by Emme.Kwok on 2026/10/11.
//
#include<bits/stdc++.h>
using namespace std;

long long a[100005];

int main() {
    int n, m, p1, s1, s2;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    long long l = 0, h = 0;
    for (int i = 1; i <= n; i++) {
        long long x = a[i] * abs(i - m);
        if (i < m) l += x;
        else if (i > m) h += x;
    }
    long long ans = 1e18, ansi = 0;
    for (int p2 = 1; p2 <= n; p2++) {
        long long x = 1LL * s2 * abs(p2 - m);
        if (p2 < m) l += x;
        else if (p2 > m) h += x;
        if (ans > abs(l - h)) {
            ans = abs(l - h);
            ansi = p2;
        }
        if (p2 < m) l -= x;
        else if (p2 > m) h -= x;
    }
    cout << ansi << endl;
    return 0;
}