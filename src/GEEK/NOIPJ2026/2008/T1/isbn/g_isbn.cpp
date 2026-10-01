//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_isbn.in", "r", stdin);
    // freopen("g_isbn.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    string original;
    cin >> original;
    vector<char> s;
    for (auto ch: original) if (ch != '-') s.push_back(ch);
    // for (auto ch: s) cout << ch; cout << "\n";
    int mod = 0;
    for (int i = 0; i < s.size() - 1; i++) mod += (i + 1) * (s[i] - '0');
    mod %= 11;
    string code = mod == 10 ? "X": to_string(mod);
    // cout << mod << "\n";
    if (code[0] == original[original.size()-1]) cout << "Right\n";
    else {
        original.replace(original.size() - 1, 1, code);
        cout << original << "\n";
    }
    return 0;
}