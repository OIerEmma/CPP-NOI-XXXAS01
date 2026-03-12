//
// Created by Emme.Kwok on 2026/2/5.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    long long k;
    string s;
    int ans = -1;
    cin >> s >> k;
    long long i = 0;
    while (k) {
        int t = (int)(s[i] - '0');
            if (k <= (long long)pow(t, 500000)) {
                ans = t;
                break;
            }
            k -= (long long)pow(t, 500000);
        ans = t;
        i++;
        cout << k << endl;
    }
    cout << ans << endl;
    return 0;
}