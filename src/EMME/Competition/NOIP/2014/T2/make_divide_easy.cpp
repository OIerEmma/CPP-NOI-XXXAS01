//
// Created by Geek.Kwok on 2026/10/6.
//
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b, l;
    cin >> a >> b >> l;
    int ans1 = l, ans2 = 1;
    for (int x = 1; x <= l; x++)
        for (int y = 1; y <= l; y++)
            if (gcd(x, y) == 1 && x * b >= y * a && x * ans2 < y * ans1)
                ans1 = x, ans2 = y;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}