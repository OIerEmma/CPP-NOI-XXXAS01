//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 100003;
long long a[maxn];

int main() {
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    int n;
    cin >> n;
    a[1] = 1;
    long long osum = 0, esum = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            esum += a[i - 1];
            a[i] = esum * i;
        } else {
            osum += a[i - 1];
            a[i] = osum * i;
        }
    }
    cout << a[n] % (int)(1e9 + 7) << endl;
    return 0;
}