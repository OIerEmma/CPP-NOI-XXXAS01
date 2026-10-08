//
// Created by Geek.Kwok on 2026/10/5.
//
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print(int p, int q) {
    if (q < 0) p = -p, q = -q;
    int g = gcd(abs(p), q);
    p /= g, q /= g;
    if (q == 1) cout << p;
    else cout << p << "/" << q;
}

int main() {
    int t, m;
    cin >> t >> m;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0) cout << "NO\n";
        else {
            if (a < 0) a = -a, b = -b, c = -c;
            int root = (int)sqrt((double)delta);
            while (root * root > delta) root--;
            while ((root + 1) * (root + 1) <= delta) root++;
            if (root * root == delta) {
                print(-b + root, 2 * a);
                cout << "\n";
            } else {
                int k = 1, r = delta;
                for (int i = 2; i * i <= r; i++)
                    while (r % (i * i) == 0) r /= i * i, k *= i;
                if (b != 0) {
                    print(-b, 2 * a);
                    cout << "+";
                }
                int g = gcd(k, 2 * a);
                int up = k / g, down = 2 * a / g;
                if (up == 1 && down == 1) cout << "sqrt(" << r << ")\n";
                else if (down == 1) cout << up << "*" << "sqrt(" << r << ")\n";
                else if (up == 1) cout << "sqrt(" << r << ")/" << down << "\n";
                else cout << up << "*sqrt(" << r << ")/" << down << "\n";
            }
        }
    }
    return 0;
}