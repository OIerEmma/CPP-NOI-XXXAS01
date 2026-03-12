//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

const int maxn = 105;
int b[maxn], t[maxn];

int main() {
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> b[i] >> t[i];
    }
    char now = 'B';
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (now == 'B') {
            if (b[i] >= t[i] - d) {
                ans += b[i];
            } else {
                ans += t[i] - d;
                now = 'T';
            }
        } else {
            if (b[i] - d > t[i]) {
                ans += b[i] - d;
                now = 'B';
            } else {
                ans += t[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}