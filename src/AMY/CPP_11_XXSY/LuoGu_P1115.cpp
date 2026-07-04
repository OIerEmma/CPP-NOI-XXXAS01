//
// Created by Emme.Kwok on 2026/7/3.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    const long long N = n;
    int a[N];
    long long pre[N];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            ans = max(ans, pre[j] - pre[i - 1]);
    cout << ans << endl;
    return 0;
}