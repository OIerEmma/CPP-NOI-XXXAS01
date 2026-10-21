//
// Created by Geek.Kwok on 2026/10/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_dragon_and_tiger_fight.in", "r", stdin);
    // freopen("g_dragon_and_tiger_fight.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, m, p1, s1, s2;
    cin >> n;
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> m >> p1 >> s1 >> s2;
    b[p1] += s1;
    long long dragonP = 0, tigerP = 0;
    for (int i = 1; i < m; i++) dragonP += b[i] * (m - i);
    for (int i = m + 1; i <= n; i++) tigerP += b[i] * (i - m);
    int newM = m;
    long long minP = abs(dragonP - tigerP);
    // cout << dragonP << " " << tigerP << endl;
    if (dragonP < tigerP) {
        for (int i = 1; i < m; i++)
            if (abs(dragonP + 1LL * s2 * (m - i) - tigerP) < minP) {
                minP = abs(dragonP + 1LL * s2 * (m - i) - tigerP);
                newM = i;
            }
    } else if (dragonP > tigerP) {
        for (int i = m + 1; i <= n; i++)
            if (abs(dragonP - 1LL * s2 * (i - m) - tigerP) < minP) {
                minP = abs(dragonP - 1LL * s2 * (i - m) - tigerP);
                newM = i;
            }
    }
    cout << newM << endl;
    return 0;
}