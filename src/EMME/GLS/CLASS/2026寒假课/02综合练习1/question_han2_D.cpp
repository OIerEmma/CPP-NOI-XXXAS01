//
// Created by Emme.Kwok on 2026/2/1.
//
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[200003], s[200003];

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = a[i] - i;
    }
    sort(s + 1, s + n + 1);
    long long b = s[(n + 1) / 2], ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - i - b);
    }
    cout << ans << endl;
    return 0;
}