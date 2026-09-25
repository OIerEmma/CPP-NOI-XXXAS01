//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

bool cmp(string &s, string &t) {
    if (s.size() != t.size()) return s.size() < t.size();
    return s < t;
}

int main() {
    int n;
    cin >> n;
    string ans = "0", a;
    int ansi = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (cmp(ans, a)) ans = a, ansi = i;
    }
    cout << ansi << endl << ans << endl;
    return 0;
}