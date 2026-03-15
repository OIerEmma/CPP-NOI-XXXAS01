//
// Created by Emme.Kwok on 2026/1/31.
//
#include <algorithm>
#include<iostream>
using namespace std;

const int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int t[10005];

bool isry(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int main() {
    char hi, mao;
    int y, m, d, h, mi;
    int y2, m2, d2, h2, mi2;
    cin >> y >> hi >> m >> hi >> d >> hi >> h >> mao >> mi;
    cin >> y2 >> hi >> m2 >> hi >> d2 >> hi >> h2 >> mao >> mi2;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    if (mi > mi2) {
        mi2 += 60;
        h2--;
    }
    mi2 -= mi;
    if (h > h2) {
        h2 += 24;
        d2--;
    }
    h2 -= h;
    if (d > d2) {
        int add = months[m];
        if (m2 == 2) {
            add += isry(y);
        }
        d2 += add;
        m2--;
    }
    d2 -= d;
    if (m > m2) {
        m2 += 12;
        y2--;
    }
    m2 -= m;
    long long minutes = mi2 + h2 * 60 + d2 * 24 * 60;
    for (int i = m; i < m2; i++) {
        minutes += months[i] * 24 * 60;
    }
    for (int j = y; j < y2; j++) {
        minutes += 365 + isry(j);
    }
    cout << minutes << endl;
    sort(t + 1, t + n + 1);
    int i = 1, ans = 0;
    while (i <= n && minutes) {
        minutes -= t[i];
        i++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}