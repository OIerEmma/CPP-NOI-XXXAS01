//
// Created by Emme.Kwok on 2026/9/21.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("apple.in", "r", stdin);
    // freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int apples = n, ans = 0, pos = 0;
    while (apples) {
        ans++;
        if (apples % 3 == 1 && !pos) pos = ans;
        apples -= (apples + 2) / 3;
    }
    cout << ans << " " << pos << "\n";
    return 0;
}