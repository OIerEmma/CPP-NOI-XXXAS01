//
// Created by Emme.Kwok on 2026/8/28.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1), dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp1[1] = a[1];
    for (int i = 2; i <= n; i++) dp1[i] = max(dp1[i - 1] + a[i], a[i]);
    for (int i = 2; i <= n; i++) dp1[i] = max(dp1[i - 1], dp1[i]);
    dp2[n] = a[n];
    for (int i = n - 1; i >= 1; i--) dp2[i] = max(dp2[i + 1] + a[i], a[i]);
    for (int i = n - 1; i >= 1; i--) dp2[i] = max(dp2[i + 1], dp2[i]);
    long long ans = dp1[1] + dp2[3];
    for (int i = 3; i < n; i++) ans = max(ans, dp1[i - 1] + dp2[i + 1]);
    cout << ans << endl;
    return 0;
}
