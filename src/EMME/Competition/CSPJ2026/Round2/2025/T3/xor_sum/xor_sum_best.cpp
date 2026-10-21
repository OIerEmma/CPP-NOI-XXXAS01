//
// Created by Emme.Kwok on 2026/10/8.
//
#include<bits/stdc++.h>
using namespace std;

const int K = 1 << 20;
int s[K];

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0, r = 1, pre = 0;
    s[0] = 1;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        pre ^= a;
        if (s[pre ^ k] == r) ans++, r++;
        s[pre] = r;
    }
    cout << ans << endl;
    return 0;
}