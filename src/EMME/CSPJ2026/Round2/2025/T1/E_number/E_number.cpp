//
// Created by Emme.Kwok on 2026/9/22.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("E_number.in", "r", stdin);
    // freopen("E_number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    vector<char> ans;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9') ans.push_back(s[i]);
    sort(ans.begin(), ans.end(), greater<>());
    for (char x : ans) cout << x;
    return 0;
}