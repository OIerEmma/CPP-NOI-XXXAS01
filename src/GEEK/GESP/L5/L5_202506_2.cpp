//
// Created by Geek.Kwok on 2026/3/10.
//
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

int n, q, a[100005], r[100005];
int memo[5005][5005];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int binary_gcd(const int* r, int begin, int end, int i) {
    if (begin == end) {
        return r[begin] + i;
    }
    if (begin + 1 == end) {
        return gcd(r[begin] + i, r[end] + i);
    }
    int mid = begin + (end - begin) / 2;
    int a = binary_gcd(r, begin, mid, i);
    int b = binary_gcd(r, mid + 1, end, i);
    if (a == 1 || b == 1) {
        return 1;
    }
    return gcd(a, b);
}

void iterate_gcd(int* r, int size) {
    int len = size;
    bool f = true;
    do {
        int maxv = 0, last = 0, j = 1;
        if (len % 2 != 0) {
            last = len;
        }
        for (int i = 1; i < len; i+=2) {
            int g;
            if (memo[r[i]][r[i+1]] > 0) {
                g = memo[r[i]][r[i+1]];
            } else {
                g = gcd(r[i], r[i+1]);
                memo[r[i]][r[i+1]] = g;
            }
            if (g == 1) {
                cout << 1 << endl;
                f = false;
                break;
            }
            r[j++] = g;
        }
        if (!f) {
            break;
        }
        if (last > 0) {
            r[j++] = r[last];
        }
        len = j - 1;
    } while (len > 1);

    if (f) {
        cout << r[len] << endl;
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        for (int j = 1; j <= n; j++) {
            r[j] = a[j] + i;
        }
        memset(memo, 0, sizeof(memo));
        iterate_gcd(r, n);
    }
    return 0;
}