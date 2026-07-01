//
// Created by Emme.Kwok on 2026/6/26.
//
#include<bits/stdc++.h>
using namespace std;

struct car {
    int a, b, diff;
};

struct site {
    int p, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x;
    cin >> n >> m >> x;
    vector<site> s(n);
    vector<car> c(m);
    for (int i = 0; i < n; i++) cin >> s[i].p >> s[i].c;
    for (int i = 0; i < m; i++) cin >> c[i].a >> c[i].b, c[i].diff = c[i].a - c[i].b;
    sort(s.begin(), s.end(), [](const site &a, const site &b) { return a.p < b.p; });
    sort(c.begin(), c.end(), [](const car &a, const car &b){ return a.diff > b.diff; });
    long long ans = 0;
    int i = 0, j = m - 1, s_front = 0, s_back = n - 1;
    while (i <= j) {
        while (c[i].diff >= 0) {
            if (s[s_front].c <= 0) s_front++;
            s[s_front].c--;
            ans += (2LL * x * c[i].b + 2LL * s[s_front].p * c[i].diff);
            i++;
        }
        while (c[j].diff < 0) {
            if (s[s_back].c <= 0) s_back--;
            s[s_back].c--;
            ans += (2LL * x * c[j].a + 2LL * (x - s[s_back].p) * (-c[j].diff));
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}