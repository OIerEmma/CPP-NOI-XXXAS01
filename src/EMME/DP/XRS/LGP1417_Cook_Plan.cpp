//
// Created by Emme.Kwok on 2026/8/27.
//
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
struct node {
    long long a, b, c;
} a[maxn];
long long ans;

bool cmp(node a, node b) {
    return a.c * b.b < b.c * a.b;
}

int main() {
    int T, n;
    cin >> T >> n;
    for (int i = 0; i < n; i++) cin >> a[i].a;
    for (int i = 0; i < n; i++) cin >> a[i].b;
    for (int i = 0; i < n; i++) cin >> a[i].c;
    sort(a, a + n, cmp);
    vector<long long> dp(T + 1, -1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = T; j >= a[i].c; j--)
            dp[j] = max(dp[j], dp[j - a[i].c] + a[i].a - j * a[i].b);
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}