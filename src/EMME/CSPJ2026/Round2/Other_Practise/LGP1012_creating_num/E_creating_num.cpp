//
// Created by Emme.Kwok on 2026/9/22.
//
#include<bits/stdc++.h>
using namespace std;

string s[25];

bool cmp(string &s, string &t) {
    return s + t > t + s;
}

int main() {
    // freopen("E_creating_num.in", "r", stdin);
    // freopen("E_creating_num.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) cout << s[i];
    return 0;
}