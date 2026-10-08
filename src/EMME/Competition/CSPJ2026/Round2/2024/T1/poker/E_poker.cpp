//
// Created by Emme.Kwok on 2026/9/20.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("E_poker.in", "r", stdin);
    // freopen("E_poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    set<string> ans;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ans.insert(s);
    }
    cout << 52 - ans.size() << endl;;
    return 0;
}