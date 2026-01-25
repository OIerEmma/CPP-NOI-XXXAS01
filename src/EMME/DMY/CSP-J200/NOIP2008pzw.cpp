//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

const int maxn = 1005;
int m, n, k, l, d, s[maxn], h[maxn], idx[maxn];

int main() {
    cin >> m >> n >> k >> l >> d;
    for (int i = 1; i <= d; i++) {
        int x, y, q, p;
        cin >> x >> y >> p >> q;
        if (x == p) {
            s[min(y, q)]++;
        } else {
            h[min(x, p)]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        idx[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (h[j] > h[i]) {
                swap(h[j], h[i]);
                swap(idx[j], idx[i]);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (idx[j] < idx[i]) {
                swap(idx[j], idx[i]);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << idx[i];
        if (i != k) {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        idx[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[j] > s[i]) {
                swap(s[j], s[i]);
                swap(idx[j], idx[i]);
            }
        }
    }
    for (int i = 1; i <= l; i++) {
        for (int j = i + 1; j <= l; j++) {
            if (idx[j] < idx[i]) {
                swap(idx[j], idx[i]);
            }
        }
    }
    for (int i = 1; i <= l; i++) {
        cout << idx[i];
        if (i != l) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}