//
// Created by Emme.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    set<char> s;
    s.insert('a');
    for (int i = 1; i <= n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        if (s.count(c)) s.insert(a);
        else s.erase(a);
    }
    if (s.size() <= 0) cout << "none\n";
    else for (auto k : s) cout << (char)k << " ";
    return 0;
}