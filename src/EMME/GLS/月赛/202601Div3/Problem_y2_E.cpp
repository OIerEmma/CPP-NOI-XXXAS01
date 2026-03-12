//
// Created by Emme.Kwok on 2026/1/27.
//
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 2 * 1e5 + 3;
int a[maxn];

int main() {
    freopen("same.in", "r", stdin);
    freopen("same.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] - a[i] == j - i) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}