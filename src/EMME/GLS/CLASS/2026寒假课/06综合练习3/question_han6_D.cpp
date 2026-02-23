//
// Created by Emme.Kwok on 2026/2/5.
//
#include<iostream>
#include<cstdio>
using namespace std;

int a[100005], psa[100005];

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        psa[i] = psa[i - 1] + a[i];
    }
    long long ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            if ((psa[r] - psa[l - 1]) % m == 0) {
                ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}