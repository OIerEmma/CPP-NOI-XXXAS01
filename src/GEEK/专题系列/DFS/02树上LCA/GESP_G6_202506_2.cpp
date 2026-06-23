//
// Created by Geek.Kwok on 6/23/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
vector<int> a(N), b(N), f(N);

void factorize(int x, vector<int> &factor) {
    int cnt = 0; factor[0] = x;
    // 最小质因数
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) f[++cnt] = i, x /= i; // 从小到大试除
    if (x > 1) f[++cnt] = x; // 剩下的大质数
    // 最大真因数：逐步除以最小质因数
    for (int i = 1; i <= cnt; i++) factor[i] = factor[i - 1] / f[i];
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        factorize(x, a);
        factorize(y, b);
        int px = 0, py = 0;
        while (a[px] != b[py]) {
            if (a[px] > b[py])  px++;
            else                py++;
        }
        cout << px + py << endl;
    }
    return 0;
}